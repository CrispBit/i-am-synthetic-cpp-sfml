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
    /*uint16_t i = 0;
    while (boost::filesystem::exists(boost::filesystem::path(Locator::getResource()->loadPath("saves/save" + patch::to_string(++i))))) {
        std::cout << "test" << std::endl;
        fileButtons.push_back(std::make_shared<FileButton>(fileButtons));
    }*/

    std::shared_ptr<FileAddButton> newFileButton = std::make_shared<FileAddButton>(&fileButtons, width, height);

    this->fileButtons = {newFileButton};
    this->gameObjects = {newFileButton};
    
    newFileButton->position();
}
