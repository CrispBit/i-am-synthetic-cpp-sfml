#include <iostream>
#include <SFML/Window.hpp>
#include <boost/filesystem.hpp>
#include "LocalResources.h"
#include "Locator.h"

int main(int argc, char** argv) {
    sf::Window window(sf::VideoMode(1280, 800), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);

    // RS::resourcesRootPath = boost::filesystem::system_complete(argv[0]);
    // std::unique_ptr<LocalResources> resources = std::make_unique<LocalResources>();
    // Locator::provide(resources);
    // Locator::getResource().loadTexture("potato");
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