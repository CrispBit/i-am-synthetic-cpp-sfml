//
// Created by cilan on 3/1/2017.
//

#include "PlayButton.h"

void PlayButton::clickHandler(sf::RenderWindow& window) {
    PlayScene().loop(window);
}
