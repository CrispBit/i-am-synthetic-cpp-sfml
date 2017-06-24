//
// Created by cilan on 6/24/2017.
//

#include "BackButton.h"

BackButton::BackButton() : MainMenuButton("Back") {
    // do nothing
}

bool BackButton::clickHandler(sf::RenderWindow& window) {
    std::cout << "going back" << std::endl;
    return false;
}
