//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"

void PlayScene::position() {
    const uint8_t gap = 5;
    const uint16_t startX = gap;
    const float startY = (game.window.getSize().y - btnHeight) / 2.5f;
    for (int i = fileButtons.size() - 1; i >= 0; i--) {
        std::shared_ptr<FileButton>& fileButton = fileButtons.at(i);
        fileButton->updatePosition(i * btnWidth + (i + 1) * gap + startX, startY);
    }
}

// the following subroutine was written by Gigi on Stack Overflow and modified by Cilan
inline static void get_all(const boost::filesystem::path& root, const std::string& ext, std::vector<boost::filesystem::path>& ret)
{
    if(!boost::filesystem::exists(root) || !boost::filesystem::is_directory(root)) return;

    boost::filesystem::recursive_directory_iterator it(root);
    boost::filesystem::recursive_directory_iterator endit;

    while(it != endit)
    {
        if(boost::filesystem::is_regular_file(*it) && it->path().extension() == ext) ret.push_back(it->path().filename());
        ++it;
    }
}

PlayScene::PlayScene(Synthy &game) : Scene(game) {
    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(game);
    this->gameObjects.push_back(newFileButton);
    this->fileButtons.push_back(newFileButton);
    
    std::shared_ptr<BackButton> backBtn = std::make_shared<BackButton>();
    std::shared_ptr<PlayLevelButton> playBtn = std::make_shared<PlayLevelButton>(fileButtons);

    backBtn->updatePosition(5, 5);
    playBtn->updatePosition(5, game.window.getSize().y - backBtn->h - 5);

    this->gameObjects.insert(this->gameObjects.end(), {backBtn, playBtn});

    std::vector<boost::filesystem::path> filePaths;
	get_all(Locator::getResource()->loadPath("saves"), ".saveme", filePaths);
	for (boost::filesystem::path path : filePaths) {
        std::string pathStr = path.filename().generic_string();
        std::shared_ptr<FileButton> newFileBtn = std::make_shared<FileButton>(fileButtons, pathStr.substr(0, pathStr.length()
                    - std::string(".saveme").length()));
        fileButtons.push_back(newFileBtn);
        gameObjects.push_back(std::move(newFileBtn));
    }

    btnWidth = newFileButton->w;
    btnHeight = newFileButton->h;
    position();
}

void PlayScene::addNewFile() {
    Data data = Data();
    data.levelid = 1;
    strncpy(data.name, fileName.c_str(), sizeof(data.name));
    std::string savePath = Locator::getResource()->loadPath("saves/" + fileName + ".saveme");
    std::ofstream saveOut(savePath, std::ios::out | std::ios::binary);
    saveOut << data;
    std::shared_ptr<FileButton> fileBtn = std::make_shared<FileButton>(fileButtons, data.name);
    fileBtn->setRelativeScale();
    this->fileButtons.insert(this->fileButtons.begin(), fileBtn);
    this->gameObjects.push_back(std::move(fileBtn));

    position();
}

void PlayScene::onEnter() {
    if (fileName != "") {
        addNewFile();
    }
}
