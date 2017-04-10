//
// Created by cilan on 4/8/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CONFIRMFILENAMEBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CONFIRMFILENAMEBUTTON_H

#include "MainMenuButton.h"

class ConfirmFilenameButton : public MainMenuButton {
    using MainMenuButton::MainMenuButton;
public:
    ~ConfirmFilenameButton(){}
    virtual void clickHandler(sf::RenderWindow& window);
};

#endif
