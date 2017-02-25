//
// Created by cilan on 1/18/2017.
//

#include "NullResources.h"

sf::Texture NullResources::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::cout << "null texture being loaded named " << id << " during " << state << " state" << " with rect width " << rect->width << " and rect height " << rect->height << "\n";
    return sf::Texture();
}

std::unique_ptr<sf::Music> NullResources::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::cout << "null music being loaded named " << id << " during " << state << " state" << "\n";
    return std::make_unique<sf::Music>();
}

std::unique_ptr<YAML::Node>
NullResources::loadYAML(std::string id) {
    // load YAML Node and return thing
    std::cout << "null YAML Node being loaded named " << id << "\n";
    return std::make_unique<YAML::Node>();
}