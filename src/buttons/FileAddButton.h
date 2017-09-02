//
// Created by cilan on 3/31/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_FILEADDBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_FILEADDBUTTON_H

#include <vector>
#include <crispsynth/buttons/Button.h>
#include <crispsynth/game-objects/GameObject.h>
#include "FileButton.h"
#include "CancelTextInputButton.h"
#include "ConfirmButton.h"
#include "../Data.h"
#include "../scenes/TextInput.h"

class Synthy;

class FileAddButton : public FileButton {
public:
    FileAddButton(Game &game);
    ~FileAddButton() {}
    void position();
private:
    void clickHandler(Game &game);
    void clickHandler(Synthy &game);
    void sHoverHandler(bool first);
    void sHoverExit();
};

#endif
