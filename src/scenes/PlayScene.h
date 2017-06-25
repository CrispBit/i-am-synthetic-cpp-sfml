//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H
#define I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H

#include "Scene.h"
#include <string>
#include <memory>
#include "../Data.h"
#include "../buttons/FileAddButton.h"
#include "../buttons/BackButton.h"
#include "../buttons/PlayLevelButton.h"

class PlayScene : public Scene {
public:
    PlayScene();
private:
    std::vector<std::shared_ptr<FileButton>> fileButtons = std::vector<std::shared_ptr<FileButton>>();
};

#endif
