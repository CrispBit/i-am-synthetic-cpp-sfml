//
// Created by cilan on 4/8/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CANCELTEXTINPUTBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_CANCELTEXTINPUTBUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "MainMenuButton.h"

class CancelTextInputButton : public MainMenuButton {
public:
    CancelTextInputButton();
    ~CancelTextInputButton(){}
    virtual void clickHandler(Game &game) override;
};

#endif
