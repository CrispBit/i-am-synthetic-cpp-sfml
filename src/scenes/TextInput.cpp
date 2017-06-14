//
// Created by cilan on 4/3/2017.
//

#include "TextInput.h"

TextInput::TextInput(std::string promptString, std::string defaultText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn, uint16_t len) {
    defaultText += "A";
    current = defaultText.length() - 1;

    for (uint16_t i = len - 1; i > current; i--) {
        defaultText += "_";
    }

    this->inputText = std::make_shared<TextObject>(defaultText, MainMenuTextures::typeFont);
    this->promptText = std::make_shared<TextObject>(promptString, MainMenuTextures::defaultFont);

    this->cancelBtn = cancelBtn;
    this->okBtn = okBtn;
    this->maxLen = len;
    this->cancelBtn->setRelativeScale();
    this->okBtn->setRelativeScale();
    const uint8_t gap = 20;
    const float btnWidth = this->cancelBtn->w;
    const float btnHeight = this->cancelBtn->h;
    this->cancelBtn->updatePosition(gap, height - gap - btnHeight);
    this->okBtn->updatePosition(width - gap - btnWidth, height - gap - btnHeight);
    sf::IntRect windowBounds = sf::IntRect(0, 0, width, height);
    if (!TextureLoader::exists("text-input/background")) {
        TextureLoader::put("text-input/background", Locator::getResource()->loadTexture("standard", "standard-repeated.jpg"));
    }
    sf::Texture& background = TextureLoader::get("text-input/background");
    background.setRepeated(true);
    this->backgroundObject = std::make_shared<SpriteObject>(background);
    this->backgroundObject->getSprite().setTextureRect(windowBounds);

    this->inputText->setCharacterSize(50);

    this->promptText->setCharacterSize(30);

    this->inputText->updateScale(1.5, 1);
    this->inputText->updatePosition((width - this->inputText->w) / 2, height / 3 + this->inputText->h / 2);

    this->inputRectangle->updateSize(this->inputText->w, this->inputText->h);
    this->inputRectangle->updateFillColor(sf::Color(255, 0, 0));
    this->inputRectangle->updatePosition(this->inputText->x, this->inputText->y);

    this->gameObjects = {this->backgroundObject, this->inputRectangle, this->promptText, this->inputText, this->cancelBtn, this->okBtn};
}

void TextInput::handleEvent(sf::Event::EventType& event) {
    // TODO
}
