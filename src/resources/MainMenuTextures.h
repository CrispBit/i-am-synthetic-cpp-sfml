//
// Created by Abraham Hamidi on 3/7/17.
//

#ifndef I_AM_SYNTHETIC_C_SFML_MAINMENUTEXTURES_H
#define I_AM_SYNTHETIC_C_SFML_MAINMENUTEXTURES_H

#include <SFML/Graphics/Texture.hpp>
#include "../Locator.h"
#include "../resources/TextureLoader.h"

class MainMenuTextures {
public:
    static void init();
    static sf::Texture  *defaultTexture,
                        *highlightedTexture,
                        *fileTexture,
                        *highlightedFileTexture,
                        *selectedFileTexture,
                        *addFileTexture,
                        *highlightedAddFileTexture;

    static sf::Font defaultFont;
};

#endif
