#include "TextureLoader.h"

std::map<std::string, sf::Texture> TextureLoader::textures;

sf::Texture& TextureLoader::get(std::string id) {
    return textures.at(id);
}

void TextureLoader::put(std::string id, sf::Texture texture) {
    textures[id] = texture;
}
