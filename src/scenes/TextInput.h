//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include "Scene.h"
#include "../resources/TextureLoader.h"
#include  "../game-objects/SpriteObject.h"
#include "../game-objects/TextObject.h"

class TextInput : public Scene {
public:
    TextInput(std::string promptString, std::string defaultText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn, uint16_t len);
private:
    std::shared_ptr<Button> cancelBtn;
    std::shared_ptr<Button> okBtn;
    std::shared_ptr<SpriteObject> backgroundObject;
    std::string result;
    uint16_t maxLen;

    std::shared_ptr<TextObject> inputText;
    std::shared_ptr<TextObject> promptText;
protected:
    virtual void handleEvent(sf::Event::EventType& event) override;
};

#endif
