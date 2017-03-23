//
// Created by Abraham Hamidi on 3/9/17.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CREDITSBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CREDITSBUTTON_H

#include "MainMenuButton.h"
#include "../scenes/CreditsScene.h"

class CreditsButton : public MainMenuButton {
    using MainMenuButton::MainMenuButton;
public:
    ~CreditsButton(){}
protected:
    virtual void clickHandler(sf::RenderWindow& window);
};

#endif
