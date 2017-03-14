//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

void Button::updateTexture() {
    this->text.setPosition(this->texture->getSize().x / 2 - this->text.getLocalBounds().width / 2, this->texture->getSize().y / 2 - this->text.getLocalBounds().height / 2);
    this->renderTexture.create(this->texture->getSize().x, this->texture->getSize().y);
    this->background.setTexture(*this->texture);
    this->renderTexture.draw(this->background);
    this->renderTexture.draw(this->text);
    this->renderTexture.display();
    this->setTexture(renderTexture.getTexture());
}

void Button::setLabel(std::string text) {
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(autoSize ? (uint16_t) (this->texture->getSize().x / this->text.getCharacterSize() * text.size()) : this->defaultSize);
    this->label = text;
}

Button::Button(std::string text, bool autoSize) {
    this->init(text, autoSize);
}

void Button::init(std::string text, bool autoSize) {
    this->autoSize = autoSize;
    this->setLabel(text);
}

Button::Button(const Button &b2) {
    this->init(b2.label, b2.autoSize);
}

void Button::update(sf::Event event, sf::RenderWindow& window) {
    int mx = sf::Mouse::getPosition(window).x;
    int my = sf::Mouse::getPosition(window).y;
    int x = (int) this->getPosition().x;
    int y = (int) this->getPosition().y;
    float w = this->getGlobalBounds().width;
    float h = this->getGlobalBounds().height;
    if (mx < x || my < y || mx > (x + w) || my > (y + h)) {
        if (isHovered) {
            isHovered = false;
            this->sHoverExit();
        }
        return;
    }
    this->event = event;
    switch (event.type) {
        case sf::Event::MouseButtonPressed:
            this->isPressed = true;
            this->sDownHandler();
            this->downHandler();
            break;
        case sf::Event::MouseButtonReleased:
            if (this->isPressed) {
                this->sClickHandler();
                this->clickHandler(window);
            }
            else this->sReleaseHandler();
            this->isPressed = false;
            break;
        case sf::Event::MouseMoved:
            this->sHoverHandler(!isHovered);
            this->hoverHandler(!isHovered);
            if (!isHovered) isHovered = true;
            break;
        default:
            break;
    }
}

const std::string Button::getText() {
    return this->label;
}
