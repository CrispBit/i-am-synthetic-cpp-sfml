//
// Created by Abraham Hamidi on 3/7/17.
//

#ifndef I_AM_SYNTHETIC_C_SFML_MAINMENUBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_MAINMENUBUTTON_H

#include "Button.h"
#include "MainMenuTextures.h"

class MainMenuButton : public Button {
public:
    MainMenuButton(std::string label, bool autoSize = false);
    ~MainMenuButton() {}
private:
    void sClickHandler();
    void sHoverHandler(bool first);
    void sHoverExit();
};


#endif //I_AM_SYNTHETIC_C_SFML_MAINMENUBUTTON_H
