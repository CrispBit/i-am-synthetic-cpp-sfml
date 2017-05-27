//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_COMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_COMPONENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class Component {
public:
    Component();
    virtual void update(sf::RenderWindow& window, uint16_t delta) {};
};

#endif
