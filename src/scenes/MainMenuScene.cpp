//
// Created by cilan on 3/18/2017.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() {
    // load main menu background
    sf::Texture& background = TextureLoader::put("main-menu/background", Locator::getResource()->loadTexture("main-menu", "background.png"));
    std::shared_ptr<SpriteObject> backgroundObject = std::make_shared<SpriteObject>(background);
    const float backgroundScale = std::max((float) width / background.getSize().x, (float) height / background.getSize().y);
    backgroundObject->updateScale(backgroundScale, backgroundScale);

    std::shared_ptr<Button> playBtn = std::make_shared<PlayButton>("Play");
    std::shared_ptr<Button> creditsBtn = std::make_shared<CreditsButton>("Credits");
    
    this->gameObjects = {backgroundObject, playBtn, creditsBtn};

    std::vector<std::shared_ptr<Button>> buttons = {playBtn, creditsBtn};

    for (uint8_t i = 0; i < buttons.size(); i++) {
        std::shared_ptr<Button> menuButton = buttons[i];
        const uint16_t startY = (uint16_t) (height - height / 1.2);
        const uint16_t startX = (uint16_t) (width / 1.5);
        const uint8_t gap = 5;
        menuButton->updatePosition(startX, i * menuButton->h * menuButton->sY + (i + 1) * gap + startY);
    }
}
