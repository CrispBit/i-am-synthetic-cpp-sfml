//
// Created by cilan on 6/24/2017.
//

#include "LevelScene.h"

LevelScene::LevelScene(Data& data) {
    timePerFrame = sf::seconds(1.f/60.f);
    std::cout << data.levelid << std::endl;
    std::string metadataPath = Locator::getResource()->loadPath("../levels/Level" + std::to_string(data.levelid) + "/Level" + std::to_string(data.levelid) + ".yaml");
    YAML::Node metadata = YAML::LoadFile(metadataPath);

    std::cout << metadata["events"][0]["type"] << std::endl;
}
