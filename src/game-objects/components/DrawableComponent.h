//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_DRAWABLECOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_DRAWABLECOMPONENT_H

#include "Component.h"
#include <SFML/Window.hpp>

class DrawableComponent : public Component {
public:
    using Component::Component;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif
