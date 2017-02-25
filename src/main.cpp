#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <boost/filesystem.hpp>
#include "resources/LocalResources.h"

void drawMain(sf::RenderWindow& mainMenu, std::vector<sf::Sprite> sprites) {
    for (sf::Sprite sprite : sprites) {
        mainMenu.draw(sprite);
    }
}

void handleTransition(sf::RenderWindow& splash, const uint16_t w, const uint16_t h, const uint16_t windowDim) {
    sf::Clock clock;
    std::unique_ptr<sf::Music> introMusic = Locator::getResource() -> loadMusic("main-menu", "intro.wav");
    introMusic -> setVolume(6); // TODO: think about this
    introMusic -> setLoop(true);
    introMusic -> play();

    const uint16_t width = w;
    const uint16_t height = h;

    for (const std::string cItem : Locator::defaultConfig) {
        YAML::Node config = std::move(*Locator::getResource() -> loadYAML("default-config"));
        std::string str = std::string(cItem);
        if (!config[str]) {
            std::cout << "3:\n";
        }
    }

    // TODO: change to RenderTexture
    sf::RenderWindow mainMenu(sf::VideoMode(0,0), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);
    mainMenu.setVisible(false);
    mainMenu.setSize(sf::Vector2u(width, height)); // must initialize with 0,0 so it doesn't appear during splash
    mainMenu.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - width / 2, sf::VideoMode::getDesktopMode().height / 2 - height / 2));

    // load main menu background
    sf::Texture background = Locator::getResource() -> loadTexture("main-menu", "background.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    const float backgroundScale = (float) (windowDim / std::max(background.getSize().x, background.getSize().y));
    backgroundSprite.setScale(backgroundScale, backgroundScale);

    while (splash.isOpen()) {
        const float timePassed = clock.getElapsedTime().asSeconds();
        if (timePassed >= 3) {
            splash.close();
        } else {
            sf::Event event;
            while (splash.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    splash.close();
                    exit(0);
                }
            }
        }
    }

    mainMenu.setVisible(true);
    splash.close();

    mainMenu.create(sf::VideoMode(width, height), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);
    mainMenu.clear();
    while (mainMenu.isOpen()) {
        sf::Event event;
        while (mainMenu.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainMenu.close();
        }
        mainMenu.clear();
        std::vector<sf::Sprite> sprites{backgroundSprite};
        drawMain(mainMenu, sprites);
    }
}

int main(int argc, char** argv) {
    const float scale = .6;

    const uint16_t width = (uint16_t) (sf::VideoMode::getDesktopMode().width * scale);
    const uint16_t height = (uint16_t) (sf::VideoMode::getDesktopMode().height * scale);
    const uint16_t windowDim = (uint16_t) (std::min(width, height) * scale);

    Locator::provideArgs(argv[0]);

    Locator::provide(std::make_unique<LocalResources>());
    sf::Texture splash = Locator::getResource() -> loadTexture("main-menu", "splash.png");
    sf::Sprite splashSprite;
    splashSprite.setScale((float) windowDim / splash.getSize().x, (float) windowDim / splash.getSize().y);
    splashSprite.setTexture(splash);

    sf::RenderWindow window(sf::VideoMode(windowDim, windowDim), "(Loading) I Am Synthetic", sf::Style::None);
    window.clear();
    window.draw(splashSprite);
    window.display();

    handleTransition(window, (uint16_t) (width / scale), (uint16_t) (height / scale), (uint16_t) (windowDim / scale));
    return 0;
}
