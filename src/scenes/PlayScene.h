//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H
#define I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H

#include <crispsynth/scenes/Scene.h>
#include <string>
#include <memory>
#include "../Data.h"
#include "../buttons/FileAddButton.h"
#include "../buttons/BackButton.h"
#include "../buttons/PlayLevelButton.h"

class PlayScene : public Scene {
public:
    PlayScene(Synthy &game);
    virtual void onEnter() override;
    std::string fileName;
private:
    float btnWidth = 0;
    float btnHeight = 0;
    void addNewFile();
    void position();
    std::vector<std::shared_ptr<FileButton>> fileButtons;
    std::shared_ptr<FileAddButton> newFileButton;
};

#endif
