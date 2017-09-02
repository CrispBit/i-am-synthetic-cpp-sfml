//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"
#include "../resources/MainMenuTextures.h"
#include "../Synthy.h"

FileAddButton::FileAddButton(Game &game) {
    this->texture = MainMenuTextures::addFileTexture;
    this->updateTexture();

    this->width = width;
    this->height = height;
    this->setRelativeScale();
}

void FileAddButton::clickHandler(Synthy &game) {
    game.transitionScene = std::make_shared<TextInput>(game, game.playScene->fileName, "Enter your name.", "Jason", 10);
    game.transitioning = true;
}

void FileAddButton::clickHandler(Game &game) {
    Game *gamePtr = &game;
    this->clickHandler(*((Synthy*)gamePtr));
}

void FileAddButton::sHoverHandler(bool first) {
    if (first) {
        this->texture = MainMenuTextures::highlightedAddFileTexture;
        this->updateTexture();
    }
}

void FileAddButton::sHoverExit() {
    this->texture = MainMenuTextures::addFileTexture;
    this->updateTexture();
}
