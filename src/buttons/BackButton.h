//
// Created by cilan on 6/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_BACKBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BACKBUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "MainMenuButton.h"

class BackButton : public MainMenuButton {
public:
    BackButton();
    ~BackButton(){}
    virtual bool clickHandler(sf::RenderWindow& window);
    void position();
};

#endif
