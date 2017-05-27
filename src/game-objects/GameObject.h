//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "components/Component.h"

class GameObject {
public:
    virtual void update(sf::RenderWindow& gWindow) = 0;
protected:
    std::vector<std::shared_ptr<Component>> components;
};

#endif
