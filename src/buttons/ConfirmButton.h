//
// Created by cilan on 4/8/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CONFIRMBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CONFIRMBUTTON_H

#include "MainMenuButton.h"

class ConfirmFilenameButton : public MainMenuButton {
public:
    ConfirmFilenameButton();
    ~ConfirmFilenameButton(){}
    virtual void clickHandler(Game &game);
private:
    bool clicked = false;
};

#endif
