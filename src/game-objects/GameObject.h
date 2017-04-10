//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_GAMEOBJECT_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class GameObject {
public:
    GameObject(std::shared_ptr<sf::Texture> t);
    sf::Sprite* getSprite();
    sf::Sprite sprite;
private:
    std::shared_ptr<sf::Texture> texture;
};

#endif
