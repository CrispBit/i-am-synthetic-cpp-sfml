//
// Created by cilan on 1/18/2017.
//

#include "NullResources.h"

sf::Texture NullResources::loadTexture(std::string id) {
    // load texture and return thing
    std::cout << "null texture being loaded named " << id << "\n";
    return sf::Texture();
}