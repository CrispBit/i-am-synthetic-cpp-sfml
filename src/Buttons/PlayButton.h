//
// Created by cilan on 3/1/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_PLAYBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_PLAYBUTTON_H


#include "Button.h"

class PlayButton : public Button {
    using Button::Button;
public:
    ~PlayButton(){}
private:
    void clickHandler();
};


#endif //I_AM_SYNTHETIC_C_SFML_PLAYBUTTON_H
