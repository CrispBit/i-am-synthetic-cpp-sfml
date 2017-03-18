//
// Created by cilan on 3/18/2017.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() {
    this->buttons = {std::make_shared<PlayButton>("Chapter Select"),
                     std::make_shared<CreditsButton>("Credits")};

    // load main menu background
    GameObject backgroundObject(std::make_shared<sf::Texture>(Locator::getResource()->loadTexture("main-menu", "background.png")));
    sf::Texture background = *backgroundObject.getSprite()->getTexture();
    const float backgroundScale = std::max((float) width / background.getSize().x, (float) height / background.getSize().y);
    backgroundObject.getSprite()->setScale(backgroundScale, backgroundScale);
    this->gameObjects = {backgroundObject};

    for (uint8_t i = 0; i < buttons.size(); i++) {
        std::shared_ptr<Button> menuButton = buttons[i];
        const uint16_t oldBtnWidth = (uint16_t) menuButton->getTexture()->getSize().x;
        const uint16_t oldBtnHeight = (uint16_t) menuButton->getTexture()->getSize().y;
        const uint16_t startY = (uint16_t) (height - height / 1.2);
        const uint16_t startX = (uint16_t) (width / 1.5);
        const uint8_t gap = 5;
        const float ratio = (float) oldBtnHeight / oldBtnWidth;
        const float scale = .1;
        const uint16_t btnWidth = (uint16_t) (width * scale);
        const uint16_t btnHeight = (uint16_t) (btnWidth * ratio);
        menuButton->setScale((float) btnWidth / oldBtnWidth, (float) btnHeight / oldBtnHeight);
        menuButton->setPosition(startX, i * btnHeight + (i + 1) * gap + startY);
    }
}
