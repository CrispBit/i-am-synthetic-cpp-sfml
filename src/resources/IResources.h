//
// Created by cilan on 1/16/2017.
//

#ifndef _IResources_h
#define _IResources_h

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <yaml-cpp/yaml.h>

class IResources {
public:
    virtual sf::Texture loadTexture(std::string state, std::string id, sf::IntRect* rect = 0) = 0;
    virtual std::unique_ptr<sf::Music> loadMusic(std::string state, std::string id) = 0;
    virtual std::string loadPath(std::string id) = 0;
    virtual sf::Font loadFont(std::string id) = 0;
    virtual sf::Image loadImage(std::string state, std::string id) = 0;
};

#endif
