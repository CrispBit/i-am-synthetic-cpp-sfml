//
// Created by Abraham Hamidi on 3/9/17.
//

#include "CreditsButton.h"
#include "../scenes/CreditsScene.h"

void CreditsButton::clickHandler(sf::RenderWindow& window) {
    CreditsScene().loop(window);
}
