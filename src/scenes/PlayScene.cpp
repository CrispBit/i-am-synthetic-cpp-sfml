//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"
#include "../Data.h"

PlayScene::PlayScene() {
    Data data = Data();
    std::ofstream save = std::ofstream(Locator::getResource()->loadPath("save"));
    data << save << std::endl;
}
