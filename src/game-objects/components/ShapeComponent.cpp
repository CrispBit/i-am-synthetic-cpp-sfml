//
// Created by cilan on 5/24/2017.
//

#include "ShapeComponent.h"

ShapeComponent::ShapeComponent() {
    // do nothing
}

void ShapeComponent::update(std::unique_ptr<sf::Shape> shape) {
    this->shape = std::move(shape);
}

void ShapeComponent::draw(sf::RenderWindow& window) {
    window.draw(*shape);
}
