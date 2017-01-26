#include <iostream>
#include <SFML/Window.hpp>
#include <boost/filesystem.hpp>
#include "LocalResources.h"

int main(int argc, char** argv) {
    Locator::provideArgs(argv[0]);

    sf::Window window(sf::VideoMode(1280, 800), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);
    Locator::provide(std::make_unique<LocalResources>());
    Locator::getResource() -> loadTexture("test");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}