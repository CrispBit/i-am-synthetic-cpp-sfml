//
// Created by cilan on 3/18/2017.
//

#include "PlayScene.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

PlayScene::PlayScene() {
    // Data data = Data();
    uint8_t i = 0;
    while (boost::filesystem::exists(boost::filesystem::path("saves/save" + patch::to_string(++i)))) {
        // display file buttons
    }

    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(&fileButtons, width, height);
    fileButtons.push_back(newFileButton);
    newFileButton->position();
    // this->fileButtons = {std::make_shared<FileAddButton>(fileButtons, width, height)};
    /* std::string savePath = Locator::getResource()->loadPath("saves/save1");
    if (!boost::filesystem::exists(boost::filesystem::path(savePath))) {
        data.levelid = 1;
    } else {
        std::ifstream saveIn = std::ifstream(savePath, std::ios::in | std::ios::binary);
        saveIn >> data;
        saveIn.close();
    }*/
}

void PlayScene::updateButtons(sf::Event event, sf::RenderWindow &window) {
    for (std::shared_ptr<Button> button : buttons) {
        button->update(event, window);
    }

    for (std::shared_ptr<Button> fileButton : fileButtons) {
        fileButton->update(event, window);
    }
}

void PlayScene::draw(sf::RenderWindow& window)  {
    window.clear();
    for (GameObject &obj : gameObjects) {
        window.draw(*obj.getSprite());
    }
    for (std::shared_ptr<Button> button : buttons) {
        window.draw(*button);
    }
    for (std::shared_ptr<Button> fileButton : fileButtons) {
        window.draw(*fileButton);
    }
    window.display();
}
