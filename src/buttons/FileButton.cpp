//
// Created by cilan on 3/29/2017.
//

#include "FileButton.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

FileButton::FileButton(std::vector<std::shared_ptr<Button>>& fileArray) : Button("File " + patch::to_string(fileArray.size()), false) {
    this->defaultSize = 350;
    this->texture = &MainMenuTextures::fileTexture;
    this->text.setCharacterSize(autoSize ? this->texture->getSize().x / (int) label.size() * 2 : defaultSize);
    this->text.setOutlineThickness((uint16_t) (this->defaultSize / 7.5));
    this->text.setFillColor(sf::Color::Green);
    this->font = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
    this->updateTexture();

    fileButtons = fileArray;
}

void FileButton::sClickHandler() {
    std::cout << this->event.type;
}

void FileButton::sHoverHandler(bool first) {
    if (first) {
        this->texture = &MainMenuTextures::highlightedFileTexture;
        this->updateTexture();
    }
}

void FileButton::sHoverExit() {
    this->texture = &MainMenuTextures::fileTexture;
    this->updateTexture();
}
