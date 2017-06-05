//
// Created by cilan on 2/25/2017.
//

#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Locator.h"
#include "../resources/MainMenuTextures.h"
#include "../game-objects/components/SpriteComponent.h"
#include "../game-objects/components/RenderComponent.h"
#include "../game-objects/GameObject.h"
#include "../game-objects/SpriteObject.h"

#ifndef I_AM_SYNTHETIC_C_SFML_BUTTON_H
#define I_AM_SYNTHETIC_C_SFML_BUTTON_H

class Button : public GameObject {
public:
    void setLabel(std::string text);
    const std::string getText();
    Button();
    Button(std::string text, bool autoSize = false);
    Button(const Button &b2);
    virtual bool update(sf::RenderWindow& window, sf::Event& event, uint16_t deltaTime) override;
    void setRelativeScale(float mod=.1);
    void updateScale(float scaleX, float scaleY);
    virtual void updatePosition(float x, float y) override;
    void updateTexture();
    virtual ~Button(){}
    sf::Event event;
    sf::Texture* texture;
    bool isPressed = false;
    bool isHovered = false;
    bool hasText = true;
private:
    sf::RenderTexture renderTexture;
    void init(std::string text, bool autoSize);
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

    std::unique_ptr<SpriteObject> spriteObj_ = std::make_unique<SpriteObject>(renderTexture.getTexture());
};

#endif
