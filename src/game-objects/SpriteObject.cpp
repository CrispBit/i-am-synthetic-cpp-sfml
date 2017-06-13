//
// Created by cilan on 5/25/2017.
//

#include "SpriteObject.h"

void SpriteObject::update() {
    _x = this->getSprite().getPosition().x;
    _y = this->getSprite().getPosition().y;
    width = this->getSprite().getGlobalBounds().width;
    height = this->getSprite().getGlobalBounds().height;
    _sX = this->getSprite().getScale().x;
    _sY = this->getSprite().getScale().y;
}

void SpriteObject::update(const sf::Texture& texture) {
    sprite_->update(texture);
    this->update();
}

SpriteObject::SpriteObject() {
    // do nothing
}

SpriteObject::SpriteObject(const sf::Texture& texture) {
    this->update(texture);
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
    this->getSprite().setScale(scaleX, scaleY);
    this->update();
}

void SpriteObject::updatePosition(float tx, float ty) {
    this->getSprite().setPosition(tx, ty);
    this->update();
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
