//
// Created by cilan on 2/25/2017.
//

#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Locator.h"
#include "resources/ButtonType.h"

#ifndef I_AM_SYNTHETIC_C_SFML_BUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BUTTON_H

class Button : public sf::Sprite {
public:
    void setLabel(std::string);
    std::string getText();
    Button(std::string, ButtonType);
private:
    std::string label;
    sf::Texture texture;
};

#endif
