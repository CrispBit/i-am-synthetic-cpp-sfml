//
// Created by cilan on 2/25/2017.
//

#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Locator.h"
#include "MainMenuTextures.h"

#ifndef I_AM_SYNTHETIC_C_SFML_BUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BUTTON_H

class Button : public sf::Sprite {
public:
    void setLabel(std::string text);
    const std::string getText();
    Button();
    Button(std::string text, bool autoSize = false);
    Button(const Button &b2);
    bool update(sf::Event event, sf::RenderWindow& window);
    void updateTexture();
    void setRelativeScale(const float scale = .1);
    virtual ~Button(){}
    sf::Event event;
    sf::Texture* texture = nullptr;
    bool isPressed = false;
    bool isHovered = false;
    bool hasText = true;
protected:
    std::string label;
    sf::Text text;
    sf::Font font;
    bool autoSize;
    uint16_t defaultSize;
    sf::Sprite background;

    virtual void sHoverExit(){}
    virtual void sClickHandler(){}
    virtual void sDownHandler(){}
    virtual void sReleaseHandler(){}
    virtual void sHoverHandler(bool first){}

    virtual bool clickHandler(sf::RenderWindow& window){return true;}
    virtual bool downHandler(){return true;}
    virtual bool hoverHandler(bool first){return true;}
private:
    sf::RenderTexture renderTexture;
    void init(std::string text, bool autoSize);
};

#endif
