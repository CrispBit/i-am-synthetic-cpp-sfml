//
// Created by cilan on 3/9/2017.
//

#ifndef _IResources_h
#define _IResources_h

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <yaml-cpp/yaml.h>

class IResources {
public:
    virtual void handleExits(sf::RenderWindow& window) = 0;
};

#endif
