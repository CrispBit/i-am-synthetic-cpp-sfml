//
// Created by Abraham Hamidi on 3/7/17.
//

#include "MainMenuTextures.h"

sf::Texture MainMenuTextures::defaultTexture;
sf::Texture MainMenuTextures::highlightedTexture;
sf::Texture MainMenuTextures::fileTexture;
sf::Texture MainMenuTextures::highlightedFileTexture;
sf::Texture MainMenuTextures::selectedFileTexture;
sf::Texture MainMenuTextures::addFileTexture;
sf::Texture MainMenuTextures::highlightedAddFileTexture;

void MainMenuTextures::init() {
    Locator::provideResourcesService(std::make_unique<LocalResources>());
    defaultTexture = Locator::getResource()->loadTexture("main-menu", "menu-button.png");
    highlightedTexture = Locator::getResource()->loadTexture("main-menu", "menu-button_highlighted.png");
    fileTexture = Locator::getResource()->loadTexture("file-select", "file-button.png");
    highlightedFileTexture = Locator::getResource()->loadTexture("file-select", "file-button_highlighted.png");
    selectedFileTexture = Locator::getResource()->loadTexture("file-select", "file-button_selected.png");
    addFileTexture = Locator::getResource()->loadTexture("file-select", "file-button_add.png");
    highlightedAddFileTexture = Locator::getResource()->loadTexture("file-select", "file-button_add_highlighted.png");
}
