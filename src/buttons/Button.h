//
// Created by cilan on 2/25/2017.
//

#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Locator.h"

#ifndef I_AM_SYNTHETIC_C_SFML_BUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BUTTON_H

class Button : public sf::Sprite {
public:
    void setLabel(std::string text);
    const std::string getText();
    Button(std::string text, bool autoSize = false);
    Button(const Button &b2);
    void update(sf::Event event, sf::RenderWindow& window);
    void updateTexture();
    virtual ~Button(){}
    sf::Event event;
    sf::Texture* texture = nullptr;
    bool isPressed = false;
    bool isHovered = false;
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

    virtual void hoverExit(){}
    virtual void clickHandler(sf::RenderWindow& window){}
    virtual void downHandler(){}
    virtual void releaseHandler(){}
    virtual void hoverHandler(bool first){}
private:
    sf::RenderTexture renderTexture;
    void init(std::string text, bool autoSize);
};

#endif
