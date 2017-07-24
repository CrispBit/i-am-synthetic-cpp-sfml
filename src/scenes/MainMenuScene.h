//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_MAINMENUSCENE_H
#define I_AM_SYNTHETIC_C_SFML_MAINMENUSCENE_H

#include "../../CrispSynth/src/Scene.h"
#include "../buttons/PlayButton.h"
#include "../buttons/CreditsButton.h"
#include "../../CrispSynth/src/game-objects/SpriteObject.h"
#include "../../CrispSynth/src/resources/TextureLoader.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene();
private:
    std::vector<std::shared_ptr<Button>> buttons;
};

#endif
