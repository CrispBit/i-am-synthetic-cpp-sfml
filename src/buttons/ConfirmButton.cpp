//
// Created by cilan on 4/8/2017.
//

#include "ConfirmButton.h"

ConfirmFilenameButton::ConfirmFilenameButton() : MainMenuButton("Cancel") {}

void ConfirmFilenameButton::clickHandler(Game &game) {
    std::cout << "click handler invoked" << std::endl;
    clicked = true;
}
