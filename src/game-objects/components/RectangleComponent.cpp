//
// Created by cilan on 5/24/2017.
//

#include "RectangleComponent.h"

RectangleComponent::RectangleComponent() {
    // do nothing
}

void RectangleComponent::update(const sf::Texture* texture) {
    this->shape.setTexture(texture);
}

void RectangleComponent::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
