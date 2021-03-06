//
// Created by cilan on 3/29/2017.
//

#include "FileButton.h"
#include "../resources/MainMenuTextures.h"

FileButton::FileButton(std::vector<std::shared_ptr<FileButton>>& fileArray, std::string name) :
    Button(name, false), fileButtons(fileArray) {
    std::ifstream file(Locator::getResource()->loadPath("saves/" + name + ".saveme"), std::ios::in | std::ios::binary);
    if (!file) exit(1);
    file >> data;
    this->defaultSize = 350;
    this->texture = MainMenuTextures::fileTexture;
    this->text.setCharacterSize(autoSize ? this->texture->getSize().x / (int) label.size() * 2 : defaultSize);
    this->text.setOutlineThickness((uint16_t) (this->defaultSize / 7.5));
    this->text.setFillColor(sf::Color::Green);
    this->font = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
    this->updateTexture();
    this->setRelativeScale();
}

void FileButton::sClickHandler() {
    if (!selected) {
        for (std::shared_ptr<FileButton>& fileButton : fileButtons) {
            fileButton->selected = false;
            fileButton->sHoverExit();
        }
        this->selected = true;
        this->texture = MainMenuTextures::selectedFileTexture;
        this->updateTexture();
    }
}

void FileButton::sHoverHandler(bool first) {
    if (first && !selected) {
        this->texture = MainMenuTextures::highlightedFileTexture;
        this->updateTexture();
    }
}

void FileButton::sHoverExit() {
    if (!selected) {
        this->texture = MainMenuTextures::fileTexture;
        this->updateTexture();
    }
}
