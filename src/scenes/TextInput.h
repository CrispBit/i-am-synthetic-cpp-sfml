//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include "Scene.h"

class TextInput : public Scene {
public:
    TextInput(std::string inputText, std::shared_ptr<Button> cancelBtn, std::shared_ptr<Button> okBtn);
private:
    std::shared_ptr<Button> cancelBtn;
    std::shared_ptr<Button> okBtn;
};

#endif
