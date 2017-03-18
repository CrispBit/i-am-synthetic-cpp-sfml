//
// Created by cilan on 3/18/2017.
//

#include "GameObject.h"

GameObject::GameObject(std::shared_ptr<sf::Texture> t) : texture(t) {
    sprite.setTexture(*texture);
}

sf::Sprite* GameObject::getSprite() {
    return &this->sprite;
}
