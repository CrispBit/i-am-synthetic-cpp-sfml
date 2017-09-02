//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_MAINMENUSCENE_H
#define I_AM_SYNTHETIC_C_SFML_MAINMENUSCENE_H

#include "../buttons/PlayButton.h"
#include "../buttons/CreditsButton.h"
#include <crispsynth/scenes/Scene.h>

class MainMenuScene : public Scene {
public:
    MainMenuScene(Game &game);
private:
    std::vector<std::shared_ptr<Button>> buttons;
};

#endif
