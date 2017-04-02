//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"

FileAddButton::FileAddButton(std::vector<std::shared_ptr<Button>>* fileArray, uint16_t width, uint16_t height) : Button() {
    this->texture = &MainMenuTextures::addFileTexture;
    this->updateTexture();

    this->width = width;
    this->height = height;

    this->fileButtons = fileArray;
}

void FileAddButton::sClickHandler() {
    this->fileButtons->insert(this->fileButtons->begin() + this->fileButtons->size() - 1, std::make_shared<FileButton>(*fileButtons));
    position();
}

void FileAddButton::sHoverHandler(bool first) {
    if (first) {
        this->texture = &MainMenuTextures::highlightedAddFileTexture;
        this->updateTexture();
    }
}

void FileAddButton::sHoverExit() {
    this->texture = &MainMenuTextures::addFileTexture;
    this->updateTexture();
}

void FileAddButton::position() {
    for (uint8_t i = 0; i < fileButtons->size(); i++) {
        std::shared_ptr<Button> fileButton = (*fileButtons)[i];
        const uint16_t oldBtnWidth = (uint16_t) fileButton->getTexture()->getSize().x;
        const uint16_t oldBtnHeight = (uint16_t) fileButton->getTexture()->getSize().y;
        const uint8_t gap = 5;
        const float ratio = (float) oldBtnHeight / oldBtnWidth;
        const float scale = .2;
        const uint16_t btnWidth = (uint16_t) (width * scale);
        const uint16_t btnHeight = (uint16_t) (btnWidth * ratio);
        const uint16_t startY = (uint16_t) ((height - btnHeight) / 2.5);
        const uint16_t startX = gap;
        fileButton->setScale((float) btnWidth / oldBtnWidth, (float) btnHeight / oldBtnHeight);
        fileButton->setPosition(i * btnWidth + (i + 1) * gap + startX, startY);
    }
}
