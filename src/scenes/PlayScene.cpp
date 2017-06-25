//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"

PlayScene::PlayScene() {
    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(gameObjects, fileButtons, width, height);
    this->gameObjects.push_back(newFileButton);
    
    std::shared_ptr<BackButton> backBtn = std::make_shared<BackButton>();
    std::shared_ptr<PlayLevelButton> playBtn = std::make_shared<PlayLevelButton>(fileButtons);

    backBtn->updatePosition(5, 5);
    playBtn->updatePosition(5, height - backBtn->h - 5);

    this->gameObjects.insert(this->gameObjects.end(), {backBtn, playBtn});

    unsigned int i = 0;
    std::string savePath;
    while (boost::filesystem::exists(boost::filesystem::path(savePath = Locator::getResource()->loadPath("saves/save" + std::to_string(++i))))) {
        Data data = Data();
        std::ifstream saveIn = std::ifstream(savePath, std::ios::in | std::ios::binary);
        saveIn >> data;
        saveIn.close();
        std::shared_ptr<FileButton> newFileBtn = std::make_shared<FileButton>(fileButtons, data.name);
        fileButtons.push_back(newFileBtn);
        gameObjects.push_back(newFileBtn);
    }

    newFileButton->position();
}
