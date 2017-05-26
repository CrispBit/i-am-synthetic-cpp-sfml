//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_DRAWABLECOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_DRAWABLECOMPONENT_H

#include "Component.h"

class DrawableComponent : public Component {
public:
    using Component::Component
    virtual void draw() = 0;
protected:
    sf::RenderWindow& gWindow;
};

#endif
