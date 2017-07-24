//
// Created by cilan on 6/28/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_STORYSCENE_H
#define I_AM_SYNTHETIC_C_SFML_STORYSCENE_H

#include "../../CrispSynth/src/Scene.h"
#include "../../CrispSynth/src/game-objects/StoryObject.h"

class StoryScene : public Scene {
public:
    StoryScene(std::queue<sf::Texture>& textures);
};

#endif
