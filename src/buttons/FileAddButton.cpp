//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"

FileAddButton::FileAddButton(std::vector<std::shared_ptr<GameObject>>& gameObjects,
        std::vector<std::shared_ptr<FileButton>>& fileArray,
        uint16_t width, uint16_t height) : Button(), fileButtons(fileArray), gameObjects(gameObjects) {
    this->texture = MainMenuTextures::addFileTexture;
    this->updateTexture();

    this->width = width;
    this->height = height;
    this->setRelativeScale();
}

bool FileAddButton::clickHandler(sf::RenderWindow& window) {
    std::shared_ptr<Button> cancelBtn = std::make_shared<CancelTextInputButton>("Cancel");
    std::shared_ptr<ConfirmFilenameButton> confirmBtn = std::make_shared<ConfirmFilenameButton>("Confirm");
    TextInput fileNameInput("Name your file", "jason", cancelBtn, confirmBtn, 10);
    fileNameInput.loop(window);
    if (confirmBtn->wasClicked()) {
        Data data = Data();
        data.levelid = 1;
        strncpy(data.name, fileNameInput.getText().c_str(), sizeof(data.name));
        std::string savePath = Locator::getResource()->loadPath("saves/" + std::string(fileNameInput.getText()) + ".saveme");
        std::ofstream saveOut(savePath, std::ios::out | std::ios::binary);
        saveOut << data;
        std::shared_ptr<FileButton> fileBtn = std::make_shared<FileButton>(fileButtons, data.name);
        fileBtn->setRelativeScale();
        this->fileButtons.insert(this->fileButtons.begin(), fileBtn);
        this->gameObjects.push_back(fileBtn);
        position();
    }
    return true;
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

void FileAddButton::position() {
    const float btnWidth = this->w;
    const float btnHeight = this->h;
    const uint8_t gap = 5;
    const uint16_t startX = gap;
    const float startY = (height - btnHeight) / 2.5f;
    for (unsigned int i = 0; i < fileButtons.size() + 1; i++) {
        if (i > 0) {
            std::shared_ptr<FileButton>& fileButton = fileButtons.at(i - 1);
            fileButton->updatePosition(i * btnWidth + (i + 1) * gap + startX, startY);
        } else {
            this->updatePosition(i * btnWidth + (i + 1) * gap + startX, startY);
        }
    }
}
