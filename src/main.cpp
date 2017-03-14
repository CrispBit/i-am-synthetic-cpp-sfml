#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <boost/filesystem.hpp>
#include "resources/LocalResources.h"
#include "Buttons/PlayButton.h"
#include "Buttons/CreditsButton.h"

void drawMain(sf::RenderWindow& mainMenu, std::vector<sf::Sprite> sprites, std::vector<std::shared_ptr<Button>> buttons) {
    mainMenu.clear();
    for (sf::Sprite &sprite : sprites) {
        mainMenu.draw(sprite);
    }
    for (std::shared_ptr<Button> button : buttons) {
        mainMenu.draw(*button);
    }
    mainMenu.display();
}

void updateButtons(std::vector<std::shared_ptr<Button>> buttons, sf::Event event, sf::RenderWindow& window) {
    for (std::shared_ptr<Button> button : buttons) {
        button->update(event, window);
    }
}

void handleTransition(sf::RenderWindow& splash, const uint16_t width, const uint16_t height) {
    sf::Clock clock;
    std::unique_ptr<sf::Music> introMusic = Locator::getResource()->loadMusic("main-menu", "intro.wav");
    introMusic -> setVolume(0); // TODO: think about this
    introMusic -> setLoop(true);
    introMusic -> play();

    std::string configPath = Locator::getResource()->loadYAML("config.yaml");
    YAML::Node config = YAML::LoadFile(configPath);

    for (auto it = Locator::defaultConfig.begin(); it != Locator::defaultConfig.end(); ++it) {
        std::string key = it->first.as<std::string>();
        if (!config[key]) {
            config[key] = Locator::defaultConfig[key];
        }
    }

    std::ofstream fout(configPath);
    fout << config;

    sf::RenderWindow mainMenu;
    mainMenu.setFramerateLimit(config["video"]["fps"].as<uint16_t>());

    // load main menu background
    sf::Texture background = Locator::getResource()->loadTexture("main-menu", "background.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    const float backgroundScale = std::max((float) width / background.getSize().x, (float) height / background.getSize().y);
    backgroundSprite.setScale(backgroundScale, backgroundScale);

    std::vector<std::shared_ptr<Button>> buttons{std::make_shared<PlayButton>("Chapter Select"),
                                                    std::make_shared<CreditsButton>("Credits")};

    for (uint8_t i = 0; i < buttons.size(); i++) {
        std::shared_ptr<Button> menuButton = buttons[i];
        const uint16_t oldBtnWidth = (uint16_t) menuButton->getTexture()->getSize().x;
        const uint16_t oldBtnHeight = (uint16_t) menuButton->getTexture()->getSize().y;
        const uint16_t startY = (uint16_t) (height - height / 1.2);
        const uint16_t startX = (uint16_t) (width / 1.5);
        const uint8_t gap = 5;
        const float ratio = (float) oldBtnHeight / oldBtnWidth;
        const float scale = .1;
        const uint16_t btnWidth = (uint16_t) (width * scale);
        const uint16_t btnHeight = (uint16_t) (btnWidth * ratio);
        menuButton->setScale((float) btnWidth / oldBtnWidth, (float) btnHeight / oldBtnHeight);
        menuButton->setPosition(startX, i * btnHeight + (i + 1) * gap + startY);
    }

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

    const bool useFullScreen = config["video"]["fullscreen"].as<bool>();
    mainMenu.create(useFullScreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode(width, height), "I Am Synthetic", useFullScreen ? sf::Style::Fullscreen : sf::Style::Titlebar + sf::Style::Close);
    mainMenu.clear();
    std::vector<sf::Sprite> sprites{backgroundSprite};

    bool active = true;
    while (mainMenu.isOpen()) {
        sf::Event event;
        while (mainMenu.pollEvent(event)) {
            do {
                switch (event.type) {
                    case sf::Event::GainedFocus:
                        active = true;
                        break;
                    case sf::Event::LostFocus:
                        active = false;
                        break;
                    case sf::Event::Closed:
                        mainMenu.close();
                        break;
                    case sf::Event::KeyPressed:
                        // TODO: make this threaded using a window subroutine from InfoWindowSubroutines
                        if (event.key.code == sf::Keyboard::Escape) {
                            if (useFullScreen)
                                mainMenu.create(sf::VideoMode(width, height), "I Am Synthetic",
                                                sf::Style::Titlebar + sf::Style::Close);
                        }
                        break;
                    default:
                        updateButtons(buttons, event, mainMenu);
                }
            } while (!active && mainMenu.waitEvent(event));
        }
        drawMain(mainMenu, sprites, buttons);
    }
}

int main(int argc, char** argv) {
    const float scale = .6;

    const uint16_t width = (uint16_t) (sf::VideoMode::getDesktopMode().width * scale);
    const uint16_t height = (uint16_t) (sf::VideoMode::getDesktopMode().height * scale);
    const uint16_t windowDim = (uint16_t) (std::min(width, height) * scale);

    Locator::provideArgs(argv[0]);
    MainMenuTextures::init();

    Locator::provideResourcesService(std::make_unique<InfoWindowSubroutines>());
    std::string defaultConfigPath = Locator::getResource()->loadYAML("default-config.yaml");
    Locator::provideConfig(defaultConfigPath);

    sf::Texture splash = Locator::getResource()->loadTexture("main-menu", "splash.png");
    sf::Sprite splashSprite;
    splashSprite.setScale((float) windowDim / splash.getSize().x, (float) windowDim / splash.getSize().y);
    splashSprite.setTexture(splash);

    sf::RenderWindow window(sf::VideoMode(windowDim, windowDim), "(Loading) I Am Synthetic", sf::Style::None);
    window.clear();
    window.draw(splashSprite);
    window.display();

    handleTransition(window, (uint16_t) (width / scale), (uint16_t) (height / scale));
    return 0;
}
