#include "TextureLoader.h"

std::map<std::string, sf::Texture> TextureLoader::textures;
std::map<std::string, std::vector<sf::Texture>> TextureLoader::spritesheetTextures;

sf::Texture& TextureLoader::get(std::string id) {
    return textures.at(id);
}

sf::Texture& TextureLoader::put(std::string id, sf::Texture texture) {
    textures[id] = texture;
    return textures[id];
}

static std::vector<sf::Texture>& TextureLoader::getSpritesheet(std::string id) {
    return spritesheetTextures.at(id);
}

static std::vector<sf::Texture>& TextureLoader::putSpritesheet(std::string id, uint16_t spriteWidth, uint16_t spriteHeight,
                                                uint16_t rows, uint16_t columns) {
    sf::Image spritesheet = Locator::getResource()->loadImage("spritesheets", id);
    std::vector<sf::Texture> tiles;
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            sf::Texture tile;
            tile.loadFromImage(spritesheet, sf::IntRect(j * spriteWidth, i * spriteHeight, spriteWidth, spriteHeight));
            tiles.push_back(std::move(tile));
        }
    }
    return spritesheetTextures[id] = std::move(tiles);
}

bool TextureLoader::exists(std::string id) {
    return !(textures.find(id) == textures.end());
}
