//
// Created by cilan on 5/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_SPRITECOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_SPRITECOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "DrawableComponent.h"

class SpriteComponent : public DrawableComponent {
public:
    SpriteComponent();
    sf::Sprite sprite;

    using DrawableComponent::update;
    virtual void draw(sf::RenderWindow& window) override;
    void update(const sf::Texture& texture);
};

#endif
