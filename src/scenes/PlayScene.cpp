//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"
#include "../Data.h"

PlayScene::PlayScene() {
    Data data = Data();
    std::string savePath = Locator::getResource()->loadPath("save");
    if (!boost::filesystem::exists(boost::filesystem::path(savePath))) {
        data.levelid = 1;
    } else {
        std::ifstream saveIn = std::ifstream(savePath, std::ios::in | std::ios::binary);
        saveIn >> data;
        saveIn.close();
    }
}
