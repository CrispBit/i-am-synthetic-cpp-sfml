//
// Created by cilan on 1/18/2017.
//

#include "NullResources.h"

sf::Texture NullResources::loadTexture(std::string id) {
    // load texture and return thing
    printf("null texture being loaded named %s", id.c_str());
    return sf::Texture();
}