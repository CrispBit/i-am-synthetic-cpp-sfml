//
// Created by cilan on 5/22/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_TEXTURELOADER_H
#define I_AM_SYNTHETIC_C_SFML_TEXTURELOADER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureLoader {
public:
    static sf::Texture& get(std::string id);
    static sf::Texture& put(std::string id, sf::Texture texture);
private:
    static std::map<std::string, sf::Texture> textures;
};

#endif
