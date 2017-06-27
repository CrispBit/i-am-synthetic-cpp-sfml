//
// Created by cilan on 3/15/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_SCENE_H
#define I_AM_SYNTHETIC_C_SFML_SCENE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../buttons/Button.h"
#include "../game-objects/GameObject.h"

class Scene {
public:
    Scene();
    virtual void loop(sf::RenderWindow& window);
protected:
    virtual bool updateObjects(sf::RenderWindow& gWindow, sf::Event& event);
    virtual void renderObjects(sf::RenderWindow& window, float delta);
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    uint16_t width, height;
    bool fullscreen;
    sf::Time timePerFrame = sf::seconds(1.f / 144.f);
};

#endif
