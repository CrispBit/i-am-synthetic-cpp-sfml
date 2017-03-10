//
// Created by cilan on 1/18/2017.
//

#include "NullResources.h"

sf::Texture NullWindowSubroutines::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::cout << "null texture being loaded named " << id << " during " << state << " state" << " with rect width " << rect->width << " and rect height " << rect->height << "\n";
    return sf::Texture();
}

std::unique_ptr<sf::Music> NullWindowSubroutines::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::cout << "null music being loaded named " << id << " during " << state << " state" << "\n";
    return std::make_unique<sf::Music>();
}

std::string NullWindowSubroutines::loadYAML(std::string id) {
    // returns YAML path
    std::cout << "null YAML Node being loaded named " << id << "\n";
    return "";
}

sf::Font NullWindowSubroutines::loadFont(std::string id) {
    // load font and return thing
    std::cout << "null font being loaded named " << id << "\n";
    return sf::Font();
}
