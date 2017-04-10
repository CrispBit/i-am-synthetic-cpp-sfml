//
// Created by cilan on 4/3/2017.
//

#include "TextInput.h"

TextInput::TextInput(std::string inputText, Button *cancelBtn, Button *okBtn) {
    this->cancelBtn = cancelBtn;
    this->okBtn = okBtn;
    sf::IntRect windowBounds = sf::IntRect(0, 0, width, height);
    std::shared_ptr<sf::Texture> background = std::make_shared<sf::Texture>(Locator::getResource()->loadTexture("standard", "standard-repeated.jpg"));
    background->setRepeated(true);
    GameObject backgroundObject = GameObject(background);
    backgroundObject.sprite.setTextureRect(windowBounds);
    this->gameObjects = {backgroundObject};
}
