//
// Created by cilan on 3/29/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_FILEBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_FILEBUTTON_H

#include "Button.h"

class FileButton : public Button {
public:
    FileButton(std::shared_ptr<std::vector<std::shared_ptr<Button>>>& fileArray, std::string name);
    ~FileButton() {}
private:
    void sClickHandler();
    void sHoverHandler(bool first);
    void sHoverExit();
    std::shared_ptr<std::vector<std::shared_ptr<Button>>>& fileButtons;
};

#endif
