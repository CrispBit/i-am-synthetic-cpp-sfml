//
// Created by Abraham Hamidi on 3/7/17.
//

#include "MainMenuTextures.h"

sf::Texture MainMenuTextures::defaultTexture;
sf::Texture MainMenuTextures::highlightedTexture;
void MainMenuTextures::init() {
    Locator::provideResourcesService(std::make_unique<LocalResources>());
    defaultTexture = Locator::getResource()->loadTexture("main-menu", "menu-button.png");
    highlightedTexture = Locator::getResource()->loadTexture("main-menu", "menu-button_highlighted.png");
}
