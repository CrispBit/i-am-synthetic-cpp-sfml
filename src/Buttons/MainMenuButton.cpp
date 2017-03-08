//
// Created by Abraham Hamidi on 3/7/17.
//

#include "MainMenuButton.h"

MainMenuButton::MainMenuButton(std::string label, bool autoSize) : Button::Button(label, autoSize) {
    this->defaultSize = 350;
    this->texture = &MainMenuTextures::defaultTexture;
    this->text.setCharacterSize(autoSize ? this->texture->getSize().x / (int) label.size() * 2 : defaultSize);
    this->text.setOutlineThickness((uint16_t) (this->defaultSize / 7.5));
    this->text.setFillColor(sf::Color::Green);
    this->font = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
    this->updateTexture();
}

void MainMenuButton::sClickHandler() {
    std::cout << this->event.type;
}

void MainMenuButton::sHoverHandler(bool first) {
    if (first) {
        this->texture = &MainMenuTextures::highlightedTexture;
        this->updateTexture();
    }
}

void MainMenuButton::sHoverExit() {
    this->texture = &MainMenuTextures::defaultTexture;
    this->updateTexture();
}
