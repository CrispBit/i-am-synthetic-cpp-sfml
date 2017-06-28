//
// Created by cilan on 6/24/2017.
//

#include "LevelScene.h"

LevelScene::LevelScene(sf::RenderWindow& window, Data& data) {
    timePerFrame = sf::seconds(1.f/60.f);
    std::cout << data.levelid << std::endl;
    std::string metadataPath = Locator::getResource()->loadPath("../levels/Level" + std::to_string(data.levelid) +
                                                                "/Level" + std::to_string(data.levelid) + ".yaml");
    YAML::Node metadata = YAML::LoadFile(metadataPath);
    std::cout << metadata["events"][0]["type"] << std::endl;

    Locator::provideMusic(Locator::getResource()->loadMusic("misc", metadata["musicfile"].as<std::string>()));
    std::unique_ptr<sf::Music>& levelMusic = Locator::getMusic();
    levelMusic->setVolume(20); // TODO: think about this
    levelMusic->setLoop(true);
    levelMusic->play();

    std::vector<std::string> imagePaths = metadata["contextimages"].as<std::vector<std::string>>();
    std::queue<sf::Texture> textures;
    for (std::string imagePath : imagePaths) {
        textures.push(Locator::getResource()->loadTexture("story-images", imagePath));
    }
    StoryScene(textures).loop(window);
}
