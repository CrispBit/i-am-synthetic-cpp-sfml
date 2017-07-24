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

bool TextureLoader::exists(std::string id) {
    return !(textures.find(id) == textures.end());
}
