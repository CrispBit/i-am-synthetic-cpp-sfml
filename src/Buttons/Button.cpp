//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

Button::isPressed = false;
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

void Button::update(sf::Event event, const sf::RenderWindow& window) {
    int mx = sf::Mouse::getPosition(window).x;
    int my = sf::Mouse::getPosition(window).y;
    int x = (int) this->getPosition().x;
    int y = (int) this->getPosition().y;
    float w = this->getGlobalBounds().width;
    float h = this->getGlobalBounds().height;
    if (mx < x || my < y || mx > (x + w) || my > (y + h)) return;
    this->event = event;
    switch (event.type) {
        case sf::Event::MouseButtonPressed:
            this->isPressed = true;
            this->downHandler();
            break;
        case sf::Event::MouseButtonReleased:
            if (this->isPressed) this->clickHandler();
            else this->releaseHandler();
            this->isPressed = false;
        default:
            break;
    }
}

const std::string Button::getText() {
    return this->label;
}
