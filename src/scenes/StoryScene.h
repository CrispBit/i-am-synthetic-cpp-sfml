//
// Created by cilan on 6/28/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_STORYSCENE_H
#define I_AM_SYNTHETIC_C_SFML_STORYSCENE_H

#include "Scene.h"
#include "../game-objects/StoryObject.h"

class StoryScene : public Scene {
public:
    StoryScene(std::queue<sf::Texture>& textures);
};

#endif
