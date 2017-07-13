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

    std::string tileDataPath = Locator::getResource()->loadPath("../levels/" + metadata["levelfile"].as<std::string>());
    std::ifstream tileData(tileDataPath, std::ios::in | std::ios::binary);

    uint16_t width, height;
    tileData.read(reinterpret_cast<char*>(&width), sizeof(uint16_t));
    tileData.read(reinterpret_cast<char*>(&height), sizeof(uint16_t));

    std::string spritesheetName = metadata["spritesheet"]["image"].as<std::string>();
    if (!TextureLoader::exists(spritesheetName) {
        TextureLoader::putSpritesheet(spritesheetName, metadata["spritesheet"]["spriteWidth"].as<uint16_t>(),
                                      metadata["spritesheet"]["spriteHeight"].as<uint16_t>(),
                                      metadata["spritesheet"]["rows"].as<uint16_t>(),
                                      metadata["spritesheet"]["columns"].as<uint16_t>());
    }

    std::vector<sf::Texture>& tileTextures = TextureLoader::getSpritesheet(spritesheetName);

    unsigned char tileIds[height][width];
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            tileData.read(reinterpret_cast<char*>(&tileIds[i][j]), sizeof(unsigned char));
            sf::Texture& texture = tileTextures[tileIds[i][j]];
        }
    }

    StoryScene(textures).loop(window);
}
