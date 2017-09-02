//
// Created by Abraham Hamidi on 3/9/17.
//

#include "CreditsButton.h"

void CreditsButton::clickHandler(Synthy &game) {
    game.transitionScene = game.creditsScene;
    game.transitioning = true;
}

void CreditsButton::clickHandler(Game &game) {
    Game *gamePtr = &game;
    this->clickHandler(*((Synthy*) gamePtr));
}
