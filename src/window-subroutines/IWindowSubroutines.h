//
// Created by cilan on 3/9/2017.
//

#ifndef _IWindowSubroutines_h
#define _IWindowSubroutines_h

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <yaml-cpp/yaml.h>

class IWindowSubroutines {
public:
    virtual void handleExits(sf::RenderWindow& window) = 0;
};

#endif
