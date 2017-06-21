//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_INPUTTEXTOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_INPUTTEXTOBJECT_H

#include "TextObject.h"

class InputTextObject : public GameObject {
public:
    InputTextObject();
    InputTextObject(std::string label, const sf::Font& font, const unsigned int len);
    virtual void updatePosition(float tx, float ty) override;
    virtual bool update(sf::RenderWindow& gWindow, sf::Event& event, uint16_t delta) override;
    void update(const std::string label, const sf::Font& font);
    void updateText(const std::string label);
    void updateScale(const float x, const float y);
    void setCharacterSize(uint16_t size);
    sf::Text& getText();
private:
    TextObject textObj;
    unsigned int current;
protected:
    virtual void update() override;
};

#endif
