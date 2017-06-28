//
// Created by cilan on 6/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_LEVELSCENE_H
#define I_AM_SYNTHETIC_C_SFML_LEVELSCENE_H

#include "Scene.h"
#include "StoryScene.h"
#include "../Data.h"
#include <queue>

class LevelScene : public Scene {
public:
    LevelScene(sf::RenderWindow& window, Data& data);
};

#endif
