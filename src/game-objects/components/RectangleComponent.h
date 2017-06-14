//
// Created by cilan on 5/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_RECTANGLECOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_RECTANGLECOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "DrawableComponent.h"

class RectangleComponent : public DrawableComponent {
public:
    RectangleComponent();
    sf::RectangleShape shape;

    using DrawableComponent::update;
    virtual void draw(sf::RenderWindow& window) override;
    void update(const sf::Texture* texture);
};

#endif
