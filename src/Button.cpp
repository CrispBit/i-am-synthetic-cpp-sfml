//
// Created by cilan on 2/25/2017.
//

#include "Button.h"

void Button::setLabel(std::string text) {
    Button::label = text;
}

Button::Button(std::string text) {
    setLabel(text);
}