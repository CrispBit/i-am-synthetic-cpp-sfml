//
// Created by cilan on 6/24/2017.
//

#include "BackButton.h"

BackButton::BackButton() : MainMenuButton("Back") {
    // do nothing
}

void BackButton::clickHandler(Game &game) {
    std::cout << "going back" << std::endl;
    game.transitionScene = game.previousScene;
    game.transitioning = true;
}
