//
// Created by cilan on 4/8/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CONFIRMBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CONFIRMBUTTON_H

#include "MainMenuButton.h"

class ConfirmFilenameButton : public MainMenuButton {
    using MainMenuButton::MainMenuButton;
public:
    ~ConfirmFilenameButton(){}
    virtual bool clickHandler(sf::RenderWindow& window);
    bool wasClicked();
private:
    bool clicked = false;
};

#endif
