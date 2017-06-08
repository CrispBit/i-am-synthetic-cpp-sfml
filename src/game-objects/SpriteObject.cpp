//
// Created by cilan on 5/25/2017.
//

#include "SpriteObject.h"

void SpriteObject::update(const sf::Texture& texture) {
    sprite_->update(texture);
    width = this->getSprite().getGlobalBounds().width;
    height = this->getSprite().getGlobalBounds().height;
}

SpriteObject::SpriteObject() {
    // do nothing
}

SpriteObject::SpriteObject(const sf::Texture& texture) {
    update(texture);
}

void SpriteObject::setRelativeScale(float factor) {
    // set relative size
    const float oldWidth = w;
    const float oldHeight = h;
    const float ratio = oldHeight / oldWidth;
    const uint16_t btnWidth = (uint16_t) (oldWidth * factor); // TODO: think about this
    const uint16_t btnHeight = (uint16_t) (btnWidth * ratio);
    this->updateScale((float) btnWidth / oldWidth, (float) btnHeight / oldHeight);
}

void SpriteObject::updateScale(float scaleX, float scaleY) {
    sprite_->sprite.setScale(scaleX, scaleY);
    _sX = scaleX;
    _sY = scaleY;
    width = this->getSprite().getGlobalBounds().width;
    height = this->getSprite().getGlobalBounds().height;
}

void SpriteObject::updatePosition(float tx, float ty) {
    sprite_->sprite.setPosition(tx, ty);
    _x = tx;
    _y = ty;
    printf("%f\n", tx);
    printf("%f\n", ty);
}

bool SpriteObject::update(sf::RenderWindow& gWindow, sf::Event::EventType& event, uint16_t delta) {
    if (delta) {
        render_->update(gWindow, drawableComponents);
    }
    return true;
}

sf::Sprite& SpriteObject::getSprite() {
    return sprite_->sprite;
}
