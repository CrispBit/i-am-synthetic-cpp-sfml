//
// Created by cilan on 5/25/2017.
//

#include "TextObject.h"

void TextObject::update() {
    _x = this->getText().getPosition().x;
    _y = this->getText().getPosition().y;
    width = this->getText().getGlobalBounds().width;
    height = this->getText().getGlobalBounds().height;
    _sX = this->getText().getScale().x;
    _sY = this->getText().getScale().y;
}

void TextObject::update(const std::string label, const sf::Font& font) {
    text_->update(label, font);
    this->update();
}

void TextObject::updateText(const std::string label) {
    text_->update(label);
    this->update();
}

void TextObject::updateScale(const float x, const float y) {
    this->getText().setScale(x, y);
    this->update();
}

void TextObject::setCharacterSize(uint16_t size) {
    this->getText().setCharacterSize(size);
    this->update();
}

TextObject::TextObject() {
    // do nothing
}

TextObject::TextObject(const std::string label, const sf::Font& font) {
    this->update(label, font);
}

void TextObject::updatePosition(float tx, float ty) {
    text_->text.setPosition(tx, ty);
    this->update();
}

void TextObject::render(sf::RenderWindow& gWindow, float delta) {
    render_->update(gWindow, drawableComponents);
}

sf::Text& TextObject::getText() {
    return text_->text;
}
