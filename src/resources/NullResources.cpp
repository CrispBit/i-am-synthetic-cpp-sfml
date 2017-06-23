//
// Created by cilan on 1/18/2017.
//

#include "NullResources.h"

sf::Texture NullResources::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::cout << "null texture being loaded named " << id << " during " << state << " state" << " with rect width " << rect->width << " and rect height " << rect->height << std::endl;
    return sf::Texture();
}

std::unique_ptr<sf::Music> NullResources::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::cout << "null music being loaded named " << id << " during " << state << " state" << std::endl;
    return std::make_unique<sf::Music>();
}

std::string NullResources::loadPath(std::string id) {
    // returns YAML path
    std::cout << "null path being loaded of file named " << id << std::endl;
    return "";
}

sf::Font NullResources::loadFont(std::string id) {
    // load font and return thing
    std::cout << "null font being loaded named " << id << std::endl;
    return sf::Font();
}
