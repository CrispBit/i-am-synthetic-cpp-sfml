//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"

// the following subroutine was written by Gigi on Stack Overflow and modified by Cilan
void get_all(const boost::filesystem::path& root, const std::string& ext, std::vector<boost::filesystem::path>& ret)
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

PlayScene::PlayScene() {
    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(gameObjects, fileButtons, width, height);
    this->gameObjects.push_back(newFileButton);
    
    std::shared_ptr<BackButton> backBtn = std::make_shared<BackButton>();
    std::shared_ptr<PlayLevelButton> playBtn = std::make_shared<PlayLevelButton>(fileButtons);

    backBtn->updatePosition(5, 5);
    playBtn->updatePosition(5, height - backBtn->h - 5);

    this->gameObjects.insert(this->gameObjects.end(), {backBtn, playBtn});

    std::vector<boost::filesystem::path> filePaths;
	get_all(Locator::getResource()->loadPath("saves"), ".saveme", filePaths);
	for (boost::filesystem::path path : filePaths) {
		std::cout << path.filename().c_str() << std::endl;
        std::string pathStr = path.filename().c_str();
        std::shared_ptr<FileButton> newFileBtn = std::make_shared<FileButton>(fileButtons, pathStr.substr(0, pathStr.length()
                    - std::string(".saveme").length()));
        fileButtons.push_back(newFileBtn);
        gameObjects.push_back(newFileBtn);
    }

    newFileButton->position();
}
