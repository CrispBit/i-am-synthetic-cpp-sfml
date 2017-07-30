//
// Created by cilan on 3/7/17.
//

#include "../resources/MainMenuTextures.h"
#include <crispsynth/resources/TextureLoader.h>
#include <crispsynth/resources/DefaultTextures.h>

sf::Texture *MainMenuTextures::defaultTexture,
            *MainMenuTextures::highlightedTexture,
            *MainMenuTextures::fileTexture,
            *MainMenuTextures::highlightedFileTexture,
            *MainMenuTextures::selectedFileTexture,
            *MainMenuTextures::addFileTexture,
            *MainMenuTextures::highlightedAddFileTexture;

void MainMenuTextures::init() {
    Locator::provideResourcesService(std::make_unique<LocalResources>());
    defaultTexture = &TextureLoader::put("main-menu/buttons/default", Locator::getResource()->loadTexture("main-menu", "menu-button.png"));
    highlightedTexture = &TextureLoader::put("main-menu/buttons/highlighted", Locator::getResource()->loadTexture("main-menu", "menu-button_highlighted.png"));
    fileTexture = &TextureLoader::put("main-menu/buttons/file", Locator::getResource()->loadTexture("file-select", "file-button.png"));
    highlightedFileTexture = &TextureLoader::put("main-menu/buttons/file_highlighted", Locator::getResource()->loadTexture("file-select", "file-button_highlighted.png"));
    selectedFileTexture = &TextureLoader::put("main-menu/buttons/file_selected", Locator::getResource()->loadTexture("file-select", "file-button_selected.png"));
    addFileTexture = &TextureLoader::put("main-menu/buttons/file-add", Locator::getResource()->loadTexture("file-select", "file-button_add.png"));
    highlightedAddFileTexture = &TextureLoader::put("main-menu/buttons/file-add_highlighted", Locator::getResource()->loadTexture("file-select", "file-button_add_highlighted.png"));

    DefaultTextures::defaultFont = Locator::getResource()->loadFont("Boogaloo-Regular.ttf");
    DefaultTextures::typeFont = Locator::getResource()->loadFont("ChessType.ttf");
}
