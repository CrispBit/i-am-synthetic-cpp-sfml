//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

void Button::setLabel(std::string text) {
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(autoSize ? this->texture.getSize().x / this->text.getCharacterSize() * text.size() : this->defaultSize);
    this->text.setPosition(this->texture.getSize().x / 2 - this->text.getLocalBounds().width / 2, this->texture.getSize().y / 2 - this->text.getLocalBounds().height / 2);
    this->label = text;
    this->renderTexture.create(this->texture.getSize().x, this->texture.getSize().y);
    this->renderTexture.draw(this->background);
    this->renderTexture.draw(this->text);
    this->renderTexture.display();
    this->setTexture(renderTexture.getTexture());
}

Button::Button(std::string text, ButtonType type, bool autoSize) {
    this->init(text, type, autoSize);
}

void Button::init(std::string text, ButtonType type, bool autoSize) {
    this->type = type;
    this->autoSize = autoSize;
    switch (type) {
        case ButtonType::mainMenu:
            this->defaultSize = 350;
            this->texture = Locator::getResource()->loadTexture("main-menu", "menu-button.png");
            this->background.setTexture(texture);
            this->text.setCharacterSize(autoSize ? this->texture.getSize().x / text.size() * 2 : defaultSize);
            this->text.setOutlineThickness((uint16_t) (this->defaultSize / 7.5));
            this->text.setFillColor(sf::Color::Green);
            this->font = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
            break;
    }

    this->setLabel(text);
}

Button::Button(const Button &b2) {
    this->init(b2.label, b2.type, b2.autoSize);
}

const std::string Button::getText() {
    return this->label;
}
