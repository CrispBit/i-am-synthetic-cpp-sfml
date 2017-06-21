//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include "Scene.h"
#include "../resources/TextureLoader.h"
#include  "../game-objects/SpriteObject.h"
#include "../game-objects/RectangleObject.h"
#include "../game-objects/InputTextObject.h"

class TextInput : public Scene {
public:
    using Scene::Scene;
    TextInput(std::string promptString, std::string defaultText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn, unsigned int len);
    std::string& getText();
private:
    std::shared_ptr<Button> cancelBtn;
    std::shared_ptr<Button> okBtn;
    std::shared_ptr<SpriteObject> backgroundObject;

    std::shared_ptr<InputTextObject> inputText;
    std::shared_ptr<TextObject> promptText;
    
    std::shared_ptr<RectangleObject> inputRectangle = std::make_shared<RectangleObject>();
    std::string result;
};

#endif
