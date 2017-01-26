//
// Created by cilan on 1/18/2017.
//

#include "LocalResources.h"

sf::Texture LocalResources::loadTexture(std::string id) {
    // load texture and return thing
    printf("loading texture named %s\n", id.c_str());
    std::cout << "Location: " << Locator::rootPath.string() << "\n";
    return sf::Texture();
}