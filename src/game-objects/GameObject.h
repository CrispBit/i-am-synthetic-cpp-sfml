//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "components/Component.h"

class GameObject {
protected:
    std::vector<std::shared_ptr<Component>> components;
    float _x, _y, _sX, _sY, width, height;
public:
    float &x = _x, &y = _y, &w = width, &h = height, &sX = _sX, &sY = _sY;
    virtual bool update(sf::RenderWindow& gWindow, sf::Event::EventType& event, uint16_t deltaTime) = 0;
    virtual void updatePosition(float tx, float ty) = 0;
};

#endif
