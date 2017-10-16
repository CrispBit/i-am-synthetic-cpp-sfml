//
// Created by cilan on 3/18/2017.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(Game &game) : Scene(game) {
    // load main menu background
    sf::Texture& background = TextureLoader::put("main-menu/background", Locator::getResource()->loadTexture("main-menu", "background.png"));
    std::shared_ptr<SpriteObject> backgroundObject = std::make_shared<SpriteObject>(background);
    const float backgroundScale = std::max((float) game.window.getSize().x / background.getSize().x, (float) game.window.getSize().y / background.getSize().y);
    backgroundObject->updateScale(backgroundScale, backgroundScale);

    std::shared_ptr<PlayButton> playBtn = std::make_shared<PlayButton>("Play");
    std::shared_ptr<CreditsButton> creditsBtn = std::make_shared<CreditsButton>("Credits");

    this->gameObjects = {backgroundObject, playBtn, creditsBtn};
    this->buttons = {playBtn, creditsBtn};

    for (uint8_t i = 0; i < buttons.size(); i++) {
        std::shared_ptr<Button> menuButton = buttons[i];
        const uint16_t startY = (uint16_t) (game.window.getSize().y - game.window.getSize().y / 1.2);
        const uint16_t startX = (uint16_t) (game.window.getSize().x / 1.5);
        const uint8_t gap = 5;
        menuButton->updatePosition(startX, i * menuButton->h + (i + 1) * gap + startY);
    }
}
