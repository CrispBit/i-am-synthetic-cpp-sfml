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

bool InputTextObject::update(sf::RenderWindow& gWindow, sf::Event& event) {
    textObj.update(gWindow, event);
    bool changed = false;
    std::string newStr = this->getText().getString();
    if (event.type == sf::Event::TextEntered && isalpha(event.text.unicode)) {
        const sf::String label = this->getText().getString();
        if (current < label.getSize() - 1) {
            newStr.at(current) = static_cast<char>(std::tolower(event.text.unicode));
            current++;
            newStr.at(current) = 'A';
            changed = true;
        }
    } else {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Left:
                case sf::Keyboard::BackSpace:
                    if (current > 0) {
                        newStr.at(current) = '_';
                        current--;
                        newStr.at(current) = 'A';
                        changed = true;
                    }
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::Space:
                    if (current < newStr.size() - 1) {
                        newStr[current] += 'a' - 'A';
                        current++;
                        newStr.at(current) = 'A';
                        changed = true;
                    }
                    break;
                case sf::Keyboard::Down:
                    if (newStr.at(current) != 'A') {
                        --newStr[current];
                        changed = true;
                    }
                    break;
                case sf::Keyboard::Up:
                    if (newStr.at(current) != 'Z') {
                        ++newStr[current];
                        changed = true;
                    }
                default:
                    break;
            }
        }
        if (changed) {
            this->updateText(newStr);
        }
    }
    return true;
}

void InputTextObject::render(sf::RenderWindow& gWindow, float delta) {
    textObj.render(gWindow, delta);
}

sf::Text& InputTextObject::getText() {
    return textObj.getText();
}

sf::String InputTextObject::getString() {
    return this->getText().getString().substring(0, current);
}
