//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include "Scene.h"

class TextInput : public Scene {
public:
    TextInput(std::string promptString, std::string defaultText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn, uint16_t len);
private:
    std::shared_ptr<Button> cancelBtn;
    std::shared_ptr<Button> okBtn;
    std::string result;
    uint16_t maxLen;

    sf::Text inputText;
    sf::Text promptText;
protected:
    virtual void handleEvent(sf::Event event);
    virtual void sDraw(sf::RenderWindow& window);
};

#endif
