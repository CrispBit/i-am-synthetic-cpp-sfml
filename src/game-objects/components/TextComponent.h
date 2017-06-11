//
// Created by cilan on 5/24/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_TEXTCOMPONENT_H
#define I_AM_SYNTHETIC_C_SFML_TEXTCOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include "DrawableComponent.h"

class TextComponent : public DrawableComponent {
public:
    TextComponent();
    sf::Text text;

    using DrawableComponent::update;
    virtual void draw(sf::RenderWindow& window) override;
    void update(const std::string label, const sf::Font& font);
    void update(const std::string label);
};

#endif
