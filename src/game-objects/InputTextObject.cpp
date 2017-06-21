//
// Created by cilan on 5/25/2017.
//

#include "InputTextObject.h"

void InputTextObject::update() {
    _x = textObj.x;
    _y = textObj.y;
    width = textObj.w;
    height = textObj.h;
    _sX = textObj.sX;
    _sY = textObj.sY;
}

void InputTextObject::update(const std::string label, const sf::Font& font) {
    textObj.update(label, font);
    this->update();
}

void InputTextObject::updateText(const std::string label) {
    textObj.updateText(label);
    this->update();
}

void InputTextObject::updateScale(const float x, const float y) {
    textObj.updateScale(x, y);
    this->update();
}

void InputTextObject::setCharacterSize(uint16_t size) {
    textObj.setCharacterSize(size);
    this->update();
}

InputTextObject::InputTextObject() {
    // do nothing
}

InputTextObject::InputTextObject(std::string label, const sf::Font& font, const unsigned int len) {
    current = (unsigned int) label.length();
    label += "A";
    for (unsigned int i = len - 1; i > current; i--) {
        label += "_";
    }
    this->update(label, font);
}

void InputTextObject::updatePosition(float tx, float ty) {
    textObj.updatePosition(tx, ty);
    this->update();
}

bool InputTextObject::update(sf::RenderWindow& gWindow, sf::Event& event, uint16_t delta) {
    textObj.update(gWindow, event, delta);
    if (!delta) {
        if (event.type == sf::Event::TextEntered) {
            printf("%c%s", static_cast<char>(event.text.unicode), "\n");
        }
    }
    return true;
}

sf::Text& InputTextObject::getText() {
    return textObj.getText();
}
