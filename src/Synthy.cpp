#include "Synthy.h"
#include "scenes/PlayScene.h"
#include "scenes/CreditsScene.h"
#include "scenes/MainMenuScene.h"

Synthy::Synthy(sf::RenderWindow &window) : Game(window) {
    this->playScene = std::make_shared<PlayScene>(*this);
    this->creditsScene = std::make_shared<CreditsScene>(*this);
    this->mainMenuScene = std::make_shared<MainMenuScene>(*this);
    this->currentScene = this->mainMenuScene;
}
