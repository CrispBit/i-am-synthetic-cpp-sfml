//
// Created by cilan on 5/25/2017.
//

#include "SpriteObject.h"

SpriteObject::SpriteObject(sf::Texture& texture) {
    sprite_->update(texture);
}

void SpriteObject::update(sf::RenderWindow& gWindow) {
    render_->update(gWindow, drawableComponents);
}

sf::Sprite& SpriteObject::getSprite() {
    return sprite_->sprite;
}
