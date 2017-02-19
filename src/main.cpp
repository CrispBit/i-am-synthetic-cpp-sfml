#include <iostream>
#include <SFML/Window.hpp>
#include <boost/filesystem.hpp>
#include "LocalResources.h"

int main(int argc, char** argv) {
    const float_t scale = .6;
    const uint16_t windowDim = (uint16_t) (std::min(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height) * scale);

    Locator::provideArgs(argv[0]);

    Locator::provide(std::make_unique<LocalResources>());
    sf::Texture splash = Locator::getResource() -> loadTexture("main-menu", "splash.png");
    sf::Sprite splashSprite;
    splashSprite.setScale((float) windowDim / splash.getSize().x, (float) windowDim / splash.getSize().y);
    splashSprite.setTexture(splash);

    sf::RenderWindow window(sf::VideoMode(windowDim, windowDim), "(Loading) I Am Synthetic", sf::Style::None);
    // don't need to clear because sprite takes up entire window
    window.draw(splashSprite);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}