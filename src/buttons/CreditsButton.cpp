//
// Created by Abraham Hamidi on 3/9/17.
//

#include "CreditsButton.h"

bool CreditsButton::clickHandler(sf::RenderWindow& window) {
    CreditsScene().loop(window);
    return true;
}
