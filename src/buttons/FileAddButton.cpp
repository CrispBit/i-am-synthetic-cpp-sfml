//
// Created by cilan on 3/31/2017.
//

#include "FileAddButton.h"

FileAddButton::FileAddButton(std::vector<std::shared_ptr<Button>>* fileArray, uint16_t width, uint16_t height) : Button() {
    this->texture = MainMenuTextures::addFileTexture;
    this->updateTexture();

    this->width = width;
    this->height = height;

    this->fileButtons = fileArray;
}

bool FileAddButton::clickHandler(sf::RenderWindow& window) {
    std::cout << "derp" << std::endl;
    std::shared_ptr<Button> cancelBtn = std::make_shared<CancelTextInputButton>("Cancel");
    std::shared_ptr<ConfirmFilenameButton> confirmBtn = std::make_shared<ConfirmFilenameButton>("Confirm");
    TextInput fileNameInput("Name your file", "jason", cancelBtn, confirmBtn, 10);
    fileNameInput.loop(window);
    if (confirmBtn->wasClicked()) {
        this->fileButtons->insert(this->fileButtons->begin() + this->fileButtons->size() - 1,
                                  std::make_shared<FileButton>(*fileButtons, fileNameInput.getText()));
        Data data = Data();
        data.levelid = 1;
        // strcpy(data.name, fileNameInput.getText().c_str());
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
    const float scale = .2;
    for (uint8_t i = 0; i < fileButtons->size(); i++) {
        std::shared_ptr<Button> fileButton = (*fileButtons)[i];
        const float oldBtnWidth = fileButton->w;
        const float oldBtnHeight = fileButton->h;
        const float ratio = oldBtnHeight / oldBtnWidth;
        const float btnWidth = width * scale;
        const float btnHeight = btnWidth * ratio;
        const float startY = (height - btnHeight) / 2.5f;
        const uint16_t startX = gap;
        fileButton->updateScale(btnWidth / oldBtnWidth, btnHeight / oldBtnHeight);
        fileButton->updatePosition(i * btnWidth + (i + 1) * gap + startX, startY);
    }
}
