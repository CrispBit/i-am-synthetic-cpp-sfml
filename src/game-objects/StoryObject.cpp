//
// Created by cilan on 6/28/2017.
//

#include "StoryObject.h"

StoryObject::StoryObject(std::queue<sf::Texture>& textures) : textures_(textures) {
    putNext();
}

void StoryObject::update() {
    _x = this->getSprite().getPosition().x;
    _y = this->getSprite().getPosition().y;
    width = this->getSprite().getGlobalBounds().width;
    height = this->getSprite().getGlobalBounds().height;
    _sX = this->getSprite().getScale().x;
    _sY = this->getSprite().getScale().y;
}

bool StoryObject::update(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::KeyReleased) {
        textures_.pop();
        return putNext();
    }
    return true;
}

bool StoryObject::putNext() {
    if (textures_.empty()) return false;
    spriteObj.update(textures_.front());
    this->update();
    return true;
}

void StoryObject::render(sf::RenderWindow &gWindow, float delta) {
    spriteObj.render(gWindow, delta);
}

void StoryObject::updateScale(float scaleX, float scaleY) {
    this->spriteObj.updateScale(scaleX, scaleY);
    this->update();
}

void StoryObject::updatePosition(float tx, float ty) {
    this->spriteObj.updatePosition(tx, ty);
    this->update();
}

sf::Sprite& StoryObject::getSprite() {
    return this->spriteObj.getSprite();
}
