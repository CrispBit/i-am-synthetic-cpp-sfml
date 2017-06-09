//
// Created by cilan on 5/24/2017.
//

#include "TextComponent.h"

TextComponent::TextComponent() {
    // do nothing
}

void TextComponent::update(const std::string label, const sf::Font& font) {
    text.setFont(font);
    text.setString(label);
}

void TextComponent::draw(sf::RenderWindow& window) {
    window.draw(text);
}
