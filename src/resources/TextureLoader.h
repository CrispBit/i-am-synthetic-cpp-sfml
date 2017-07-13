//
// Created by cilan on 5/22/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_TEXTURELOADER_H
#define I_AM_SYNTHETIC_C_SFML_TEXTURELOADER_H

#include "../Locator.h"
#include <SFML/Graphics.hpp>
#include <map>

class TextureLoader {
public:
    static sf::Texture& get(std::string id);
    static sf::Texture& put(std::string id, sf::Texture texture);

    static std::vector<sf::Texture>& getSpritesheet(std::string id);
    static std::vector<sf::Texture>& putSpritesheet(std::string id, uint16_t spriteWidth, uint16_t spriteHeight,
                                                    uint16_t rows, uint16_t columns);

    static bool exists(std::string id);
private:
    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, std::vector<sf::Texture>> spritesheetTextures;
};

#endif
