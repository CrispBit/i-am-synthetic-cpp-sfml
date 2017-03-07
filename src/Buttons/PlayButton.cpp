//
// Created by cilan on 3/1/2017.
//

#include "PlayButton.h"

void PlayButton::clickHandler() {
    std::cout << this->event.type;
}

void PlayButton::hoverHandler(bool first) {
   if (first) {
        this->texture = Locator::getResource()->loadTexture("main-menu", "menu-button_highlighted.png");
        this->updateTexture();
   }
}

void PlayButton::hoverExit() {
    this->texture = Locator::getResource()->loadTexture("main-menu", "menu-button.png");
    this->updateTexture();
}
