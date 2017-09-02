//
// Created by cilan on 6/28/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_STORYSCENE_H
#define I_AM_SYNTHETIC_C_SFML_STORYSCENE_H

#include <crispsynth/scenes/Scene.h>
#include <crispsynth/game-objects/StoryObject.h>

class StoryScene : public Scene {
public:
    StoryScene(Game &game, std::queue<sf::Texture>& textures);
};

#endif
