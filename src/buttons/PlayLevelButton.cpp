//
// Created by cilan on 6/24/2017.
//

#include "PlayLevelButton.h"

PlayLevelButton::PlayLevelButton(std::vector<std::shared_ptr<FileButton>>& fileButtons) :
    MainMenuButton("Play Level"), fileButtons(fileButtons) {
    // do nothing
}

void PlayLevelButton::clickHandler(Synthy &game) {
    for (std::shared_ptr<FileButton>& fileButton : fileButtons) {
        if (fileButton->selected) {
            game.transitionScene = std::make_unique<LevelScene>(game, fileButton->data);
            game.transitioning = true;
        }
    }
}
