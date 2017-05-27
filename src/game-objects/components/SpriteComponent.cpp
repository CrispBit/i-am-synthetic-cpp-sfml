//
// Created by cilan on 5/24/2017.
//

#include "SpriteComponent.h"

SpriteComponent::SpriteComponent() {
    // do nothing
}

void SpriteComponent::update(sf::Texture& texture) {
    sprite.setTexture(texture);
}

void SpriteComponent::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
