//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

void Button::setLabel(std::string text) {
    Button::label = text;
}

Button::Button(std::string text, ButtonType type) {
    setLabel(text);
    switch (type) {
        case ButtonType::mainMenu:
            texture = Locator::getResource()->loadTexture("main-menu", "menu-button.png");
            break;
    }
    this->setTexture(texture);
}

std::string Button::getText() {
    return Button::label;
}
