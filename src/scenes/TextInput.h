//
// Created by cilan on 4/3/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H
#define I_AM_SYNTHETIC_C_SFML_ITEXTINPUT_H

#include "Scene.h"

class TextInput : public Scene {
public:
    TextInput(std::string inputText, Button *cancelBtn, Button *okBtn);
private:
    Button *cancelBtn;
    Button *okBtn;
};

#endif
