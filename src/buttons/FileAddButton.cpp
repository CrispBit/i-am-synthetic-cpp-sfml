//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"

FileAddButton::FileAddButton(std::vector<std::shared_ptr<GameObject>>& gameObjects,
        std::shared_ptr<std::vector<std::shared_ptr<Button>>>& fileArray,
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
        std::shared_ptr<FileButton> fileBtn = std::make_shared<FileButton>(fileButtons, fileNameInput.getText());
        fileBtn->setRelativeScale();
        this->fileButtons->insert(this->fileButtons->begin() + this->fileButtons->size() - 1, fileBtn);
        this->gameObjects.push_back(fileBtn);
        Data data = Data();
        data.levelid = 1;
        strcpy(data.name, fileNameInput.getText().c_str());
        std::string savePath = Locator::getResource()->loadPath(
                "saves/save" + std::to_string(this->fileButtons->size() - 1));
        std::ofstream saveOut = std::ofstream(savePath, std::ios::out | std::ios::binary);
        saveOut << data;
        saveOut.close();
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
    const uint8_t gap = 5;
    for (unsigned int i = 0; i < fileButtons->size(); i++) {
        std::shared_ptr<Button>& fileButton = fileButtons->at(i);
        const float btnWidth = fileButton->w;
        const float btnHeight = fileButton->h;
        const float startY = (height - btnHeight) / 2.5f;
        const uint16_t startX = gap;
        fileButton->updatePosition(i * btnWidth + (i + 1) * gap + startX, startY);
    }
}
