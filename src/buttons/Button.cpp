//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

Button::Button(std::string text, bool autoSize) {
    this->init(text, autoSize);
}

Button::Button() {
    this->hasText = false;
}

void Button::setRelativeScale(float mod) {
    spriteObj_.setRelativeScale(mod);
}

void Button::updateScale(float scaleX, float scaleY) {
    spriteObj_.updateScale(scaleX, scaleY);
}

void Button::init(std::string text, bool autoSize) {
    this->autoSize = autoSize;
    this->setLabel(text);
}

void Button::updateTexture() {
    this->renderTexture.create(this->texture->getSize().x, this->texture->getSize().y);
    this->background.setTexture(*this->texture);
    this->renderTexture.draw(this->background);
    if (this->hasText) {
        this->text.setPosition(this->texture->getSize().x / 2 - this->text.getLocalBounds().width / 2, this->texture->getSize().y / 2 - this->text.getLocalBounds().height / 2);
        this->renderTexture.draw(this->text);
    }
    this->renderTexture.display();
    this->spriteObj_.update(renderTexture.getTexture());
}

void Button::updatePosition(float x, float y) {
    spriteObj_.updatePosition(x, y);
}

void Button::setLabel(std::string text) {
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(autoSize ? (uint16_t) (this->texture->getSize().x / this->text.getCharacterSize() * text.size()) : this->defaultSize);
    this->label = text;
}

bool Button::update(sf::RenderWindow& gWindow, sf::Event::EventType& event, uint16_t delta) {
    bool stay = true;
    if (!delta) {
        int mx = sf::Mouse::getPosition(gWindow).x;
        int my = sf::Mouse::getPosition(gWindow).y;
        if (mx < x || my < y || mx > (x + w) || my > (y + h)) {
            if (isHovered) {
                isHovered = false;
                this->sHoverExit();
            }
        } else {
            switch (event) {
                case sf::Event::MouseButtonPressed:
                    this->isPressed = true;
                    this->sDownHandler();
                    stay = this->downHandler();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (this->isPressed) {
                        this->sClickHandler();
                        stay = this->clickHandler(gWindow);
                    }
                    else this->sReleaseHandler();
                    this->isPressed = false;
                    break;
                case sf::Event::MouseMoved:
                    this->sHoverHandler(!isHovered);
                    stay = this->hoverHandler(!isHovered);
                    if (!isHovered) isHovered = true;
                    break;
                default:
                    break;
            }
        }
    }
    return stay && spriteObj_.update(gWindow, event, delta);
}

const std::string Button::getText() {
    return this->label;
}
