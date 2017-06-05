//
// Created by Abraham Hamidi on 3/7/17.
//

#include "MainMenuTextures.h"

sf::Texture *MainMenuTextures::defaultTexture,
            *MainMenuTextures::highlightedTexture,
            *MainMenuTextures::fileTexture,
            *MainMenuTextures::highlightedFileTexture,
            *MainMenuTextures::selectedFileTexture,
            *MainMenuTextures::addFileTexture,
            *MainMenuTextures::highlightedAddFileTexture;

sf::Font MainMenuTextures::defaultFont;

void MainMenuTextures::init() {
    Locator::provideResourcesService(std::make_unique<LocalResources>());
    defaultTexture = &TextureLoader::put("main-menu/buttons/default", Locator::getResource()->loadTexture("main-menu", "menu-button.png"));
    highlightedTexture = &TextureLoader::put("main-menu/buttons/highlighted", Locator::getResource()->loadTexture("main-menu", "menu-button_highlighted.png"));
    fileTexture = &TextureLoader::put("main-menu/buttons/file", Locator::getResource()->loadTexture("file-select", "file-button.png"));
    highlightedFileTexture = &TextureLoader::put("main-menu/buttons/file_highlighted", Locator::getResource()->loadTexture("file-select", "file-button_highlighted.png"));
    selectedFileTexture = &TextureLoader::put("main-menu/buttons/file_selected", Locator::getResource()->loadTexture("file-select", "file-button_selected.png"));
    addFileTexture = &TextureLoader::put("main-menu/buttons/file-add", Locator::getResource()->loadTexture("file-select", "file-button_add.png"));
    highlightedAddFileTexture = &TextureLoader::put("main-menu/buttons/file-add_highlighted", Locator::getResource()->loadTexture("file-select", "file-button_add_highlighted.png"));

    defaultFont = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
}
