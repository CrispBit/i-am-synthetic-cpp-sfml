//
// Created by cilan on 3/1/2017.
//

#include "PlayButton.h"

bool PlayButton::clickHandler(sf::RenderWindow& window) {
    PlayScene().loop(window);
    return true;
}
