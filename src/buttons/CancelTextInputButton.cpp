//
// Created by cilan on 4/8/2017.
//

#include "CancelTextInputButton.h"

CancelTextInputButton::CancelTextInputButton() : MainMenuButton("Cancel") {}

void CancelTextInputButton::clickHandler(Game &game) {
    std::cout << "cancelling text input" << std::endl;
}
