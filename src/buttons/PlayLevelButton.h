//
// Created by cilan on 3/1/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_PLAYLEVELBUTTON_H
#define I_AM_SYNTHETIC_C_SFML_PLAYLEVELBUTTON_H

#include "../scenes/LevelScene.h"
#include "MainMenuButton.h"
#include "FileButton.h"
#include "../Synthy.h"

class PlayLevelButton : public MainMenuButton {
public:
    PlayLevelButton(std::vector<std::shared_ptr<FileButton>>& fileButtons);
    ~PlayLevelButton(){}
protected:
    using Button::clickHandler;
    virtual void clickHandler(Synthy &game);
private:
    std::vector<std::shared_ptr<FileButton>>& fileButtons;
};

#endif
