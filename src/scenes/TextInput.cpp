//
// Created by cilan on 4/3/2017.
//

#include "TextInput.h"
#include <crispsynth/resources/DefaultTextures.h>

TextInput::TextInput(Game &game, std::string &returnString, std::string promptString, std::string defaultText, unsigned int len) : Scene(game) {
    this->inputText = std::make_shared<InputTextObject>(defaultText, DefaultTextures::typeFont, len);
    this->promptText = std::make_shared<TextObject>(promptString, DefaultTextures::defaultFont);

    this->cancelBtn->setRelativeScale();
    this->okBtn->setRelativeScale();
    const uint8_t gap = 20;
    const float btnWidth = this->cancelBtn->w;
    const float btnHeight = this->cancelBtn->h;
    this->cancelBtn->updatePosition(gap, game.window.getSize().y - gap - btnHeight);
    this->okBtn->updatePosition(game.window.getSize().x - gap - btnWidth, game.window.getSize().y - gap - btnHeight);
    sf::IntRect windowBounds = sf::IntRect(0, 0, game.window.getSize().x, game.window.getSize().y);
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
    this->inputText->updatePosition((game.window.getSize().x - this->inputText->w) / 2, game.window.getSize().y / 3 + this->inputText->h / 2);

    this->inputRectangle->updateSize(this->inputText->w + this->inputText->getText().getCharacterSize() / 2, this->inputText->h + this->inputText->getText().getCharacterSize() / 2);
    this->inputRectangle->updateFillColor(sf::Color(122, 25, 18, 200));
    this->inputRectangle->updatePosition(this->inputText->x, this->inputText->y);

    this->gameObjects = {this->backgroundObject, this->inputRectangle, this->promptText, this->inputText, this->cancelBtn, this->okBtn};
}

std::string& TextInput::getText() {
    result = this->inputText->getString();
    return result;
}
