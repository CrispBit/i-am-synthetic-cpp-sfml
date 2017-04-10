//
// Created by cilan on 3/31/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_FILEADDBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_FILEADDBUTTON_H

#include <vector>
#include "Button.h"
#include "FileButton.h"
#include "CancelTextInputButton.h"
#include "ConfirmFilenameButton.h"
#include "../Data.h"
#include "../scenes/TextInput.h"

class FileAddButton : public Button {
public:
    FileAddButton(std::vector<std::shared_ptr<Button>>* fileArray, uint16_t width, uint16_t height);
    ~FileAddButton() {}
    void position();
private:
    uint16_t width, height;
    bool clickHandler(sf::RenderWindow& window);
    void sHoverHandler(bool first);
    void sHoverExit();
    std::vector<std::shared_ptr<Button>> *fileButtons;
};

#endif
