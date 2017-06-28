//
// Created by cilan on 6/28/2017.
//

#include "StoryScene.h"

StoryScene::StoryScene(std::queue<sf::Texture>& textures) {
    std::shared_ptr<StoryObject> storyObj = std::make_shared<StoryObject>(textures);
    const float backgroundScale = std::max(width / storyObj->w, height / storyObj->h);
    storyObj->updateScale(backgroundScale, backgroundScale);
    storyObj->updatePosition(0, 0);
    gameObjects.push_back(std::move(storyObj));
}
