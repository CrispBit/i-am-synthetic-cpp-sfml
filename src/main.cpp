#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char** argv) {
    sf::Window window(sf::VideoMode(1280, 800), "I Am Synthetic", sf::Style::Titlebar + sf::Style::Close);

    // RS::resourcesRootPath = boost::filesystem::system_complete(argv[0]);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}