//
// Created by cilan on 5/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_SHAPECOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_SHAPECOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "DrawableComponent.h"
#include <memory>

class ShapeComponent : public DrawableComponent {
public:
    ShapeComponent();
    sf::Shape* shape;

    using DrawableComponent::update;
    virtual void draw(sf::RenderWindow& window) override;
    void update(sf::Shape& shape);
};

#endif
