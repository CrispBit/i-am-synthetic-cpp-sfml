//
// Created by cilan on 6/28/2017.
//

#include "StoryScene.h"

StoryScene::StoryScene(Game &game, std::queue<sf::Texture>& textures) : Scene(game) {
    std::shared_ptr<StoryObject> storyObj = std::make_shared<StoryObject>(textures);
    const float backgroundScale = std::max(game.window.getSize().x / storyObj->w, game.window.getSize().y / storyObj->h);
    storyObj->updateScale(backgroundScale, backgroundScale);
    storyObj->updatePosition(0, 0);
    gameObjects.push_back(std::move(storyObj));
}
