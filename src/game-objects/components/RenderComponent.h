//
// Created by cilan on 5/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_RENDERCOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_RENDERCOMPONENT_H

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "DrawableComponent.h"

class RenderComponent : public Component {
public:
    RenderComponent();

    using Component::update;
    virtual void update(sf::RenderWindow& window, std::vector<std::weak_ptr<DrawableComponent>>&);
};

#endif
