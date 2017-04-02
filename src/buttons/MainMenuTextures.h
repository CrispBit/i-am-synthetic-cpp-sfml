//
// Created by Abraham Hamidi on 3/7/17.
//

#ifndef I_AM_SYNTHETIC_C_SFML_MAINMENUTEXTURES_H
#define I_AM_SYNTHETIC_C_SFML_MAINMENUTEXTURES_H


#include <SFML/Graphics/Texture.hpp>
#include "../Locator.h"

class MainMenuTextures {
public:
    static void init();
    static sf::Texture defaultTexture;
    static sf::Texture highlightedTexture;
    static sf::Texture fileTexture;
    static sf::Texture highlightedFileTexture;
    static sf::Texture selectedFileTexture;
    static sf::Texture addFileTexture;
    static sf::Texture highlightedAddFileTexture;
};

#endif
