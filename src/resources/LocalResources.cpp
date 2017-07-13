//
// Created by cilan on 1/18/2017.
//

#include "LocalResources.h"

sf::Texture LocalResources::loadTexture(std::string state, std::string id, sf::IntRect* rect) {
    // load texture and return thing
    std::string path = (Locator::rootPath / "assets" / "images" / state / id).generic_string();

    printf("loading texture named %s\n", id.c_str());

    sf::Texture returnTexture;
    if (rect != 0) {
        returnTexture.loadFromFile(path, *rect);
    } else {
        returnTexture.loadFromFile(path);
    }

    return returnTexture;
}

std::unique_ptr<sf::Music> LocalResources::loadMusic(std::string state, std::string id) {
    // load music and return thing
    std::string path = (Locator::rootPath / "assets" / "audio" / "music" / state / id).generic_string();

    printf("loading music named %s\n", id.c_str());

    std::unique_ptr<sf::Music> returnMusic = std::make_unique<sf::Music>();
    returnMusic->openFromFile(path);

    return returnMusic;
}

std::string LocalResources::loadPath(std::string id) {
    // returns path
    std::string path = (Locator::rootPath / "assets" / "config" / id).generic_string();

    printf("loading path of file named %s\n", id.c_str());

    return path;
}

sf::Font LocalResources::loadFont(std::string id) {
    // load font and return thing
    std::string path = (Locator::rootPath / "assets" / "fonts" / id).generic_string();
    sf::Font font;
    font.loadFromFile(path);

    printf("loading font named %s\n", id.c_str());

    return font;
}

sf::Image LocalResources::loadImage(std::string state, std::string id) {
    // load image and return thing
    std::string path = (Locator::rootPath / "assets" / "images" / state / id).generic_string();

    printf("loading image named %s\n", id.c_str());

    sf::Image returnImage;
    returnImage.loadFromFile(path);

    return returnImage;
}
