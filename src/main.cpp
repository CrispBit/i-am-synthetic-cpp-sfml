#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <boost/filesystem.hpp>
#include "resources/LocalResources.h"

void handleTransition(sf::RenderWindow& splash, const uint16_t w, const uint16_t h) {
    sf::Clock clock;
    std::unique_ptr<sf::Music> introMusic = Locator::getResource() -> loadMusic("main-menu", "intro.wav");
    introMusic -> setVolume(6); //TODO: think about this
    introMusic -> setLoop(true);
    introMusic -> play();

    const uint16_t width = w;
    const uint16_t height = h;

    sf::RenderWindow mainMenu(sf::VideoMode(0,0), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);
    mainMenu.setVisible(false);
    mainMenu.setSize(sf::Vector2u(width, height)); // must initialize with 0,0 so it doesn't appear during splash
    mainMenu.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - width / 2, sf::VideoMode::getDesktopMode().height / 2 - height / 2));

    const float timePassed = clock.getElapsedTime().asSeconds();
    sf::sleep(sf::seconds(3 - timePassed));

    mainMenu.setVisible(true);
    splash.close();

    mainMenu.create(sf::VideoMode(width, height), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);
    while (mainMenu.isOpen()) {
        sf::Event event;
        while (mainMenu.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainMenu.close();
        }
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
    // no need to clear because sprite takes up entire window
    window.draw(splashSprite);
    window.display();

    handleTransition(window, width, height);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
