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
    void setLabel(std::string text);
    const std::string getText();
    Button(std::string text, ButtonType type, bool autoSize = false);
    Button(const Button &b2);
private:
    std::string label;
    sf::Text text;
    sf::Font font;
    sf::Sprite background;
    sf::Texture texture;
    sf::RenderTexture renderTexture;
    ButtonType type;
    bool autoSize;
    uint16_t defaultSize;
    void init(std::string text, ButtonType type, bool autoSize);
};

#endif
