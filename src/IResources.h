//
// Created by cilan on 1/16/2017.
//

#ifndef _IResources_h
#define _IResources_h

#include <string>
#include <SFML/Graphics.hpp>

class IResources {
public:
    ~IResources() {}
    virtual sf::Texture loadTexture(std::string id) = 0;
};

#endif