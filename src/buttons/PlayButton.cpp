//
// Created by cilan on 3/1/2017.
//

#include "PlayButton.h"

void PlayButton::clickHandler(Synthy &game) {
    game.transitionScene = game.playScene;
    game.transitioning = true;
}

void PlayButton::clickHandler(Game &game) {
    Game *gamePtr = &game;
    this->clickHandler(*((Synthy*) gamePtr));
}
