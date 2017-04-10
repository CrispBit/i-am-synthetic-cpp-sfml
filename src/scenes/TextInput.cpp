//
// Created by cilan on 4/3/2017.
//

#include "TextInput.h"

TextInput::TextInput(std::string inputText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn) {
    this->cancelBtn = cancelBtn;
    this->okBtn = okBtn;
    this->cancelBtn->setRelativeScale();
    this->okBtn->setRelativeScale();
    const uint8_t gap = 20;
    const float btnWidth = this->cancelBtn->getTexture()->getSize().x * this->cancelBtn->getScale().x;
    const float btnHeight = this->cancelBtn->getTexture()->getSize().y * this->cancelBtn->getScale().y;
    this->cancelBtn->setPosition(gap, height - gap - btnHeight);
    this->okBtn->setPosition(width - gap - btnWidth, height - gap - btnHeight);
    sf::IntRect windowBounds = sf::IntRect(0, 0, width, height);
    std::shared_ptr<sf::Texture> background = std::make_shared<sf::Texture>(Locator::getResource()->loadTexture("standard", "standard-repeated.jpg"));
    background->setRepeated(true);
    GameObject backgroundObject = GameObject(background);
    backgroundObject.sprite.setTextureRect(windowBounds);
    this->gameObjects = {backgroundObject};
    this->buttons = {this->cancelBtn, this->okBtn};
}
