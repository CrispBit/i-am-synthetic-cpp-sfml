//
// Created by cilan on 6/24/2017.
//

#include "PlayLevelButton.h"

PlayLevelButton::PlayLevelButton(std::vector<std::shared_ptr<FileButton>>& fileButtons) :
    MainMenuButton("Play Level"), fileButtons(fileButtons) {
    // do nothing
}

bool PlayLevelButton::clickHandler(sf::RenderWindow& window) {
    for (std::shared_ptr<FileButton>& fileButton : fileButtons) {
        if (fileButton->selected) {
            // loop playing scene
            return false;
        }
    }
    return true;
}
