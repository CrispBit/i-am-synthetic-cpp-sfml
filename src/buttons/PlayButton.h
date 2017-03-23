//
// Created by cilan on 3/1/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_PLAYBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_PLAYBUTTON_H

#include "MainMenuButton.h"
#include "../scenes/PlayScene.h"

class PlayButton : public MainMenuButton {
    using MainMenuButton::MainMenuButton;
public:
    ~PlayButton(){}
    virtual void clickHandler(sf::RenderWindow& window);
};

#endif
