//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include <crispsynth/scenes/Scene.h>
#include <crispsynth/resources/TextureLoader.h>
#include <crispsynth/game-objects/SpriteObject.h>
#include <crispsynth/game-objects/RectangleObject.h>
#include <crispsynth/game-objects/InputTextObject.h>
#include "../buttons/CancelTextInputButton.h"
#include "../buttons/ConfirmButton.h"

class TextInput : public Scene {
public:
    using Scene::Scene;
    TextInput(Game &game, std::string &returnString, std::string promptString, std::string defaultText, unsigned int len);
    std::string& getText();
private:
    std::shared_ptr<CancelTextInputButton> cancelBtn;
    std::shared_ptr<ConfirmFilenameButton> okBtn;
    std::shared_ptr<SpriteObject> backgroundObject;

    std::shared_ptr<InputTextObject> inputText;
    std::shared_ptr<TextObject> promptText;
    
    std::shared_ptr<RectangleObject> inputRectangle = std::make_shared<RectangleObject>();
    std::string result;
};

#endif
