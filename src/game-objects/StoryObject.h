//
// Created by cilan on 6/28/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_STORYOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_STORYOBJECT_H

#include "SpriteObject.h"
#include <queue>

class StoryObject : public GameObject {
public:
    StoryObject(std::queue<sf::Texture>& textures);
    bool update(sf::RenderWindow& gWindow, sf::Event& event);
    virtual void update() override;
    void render(sf::RenderWindow& gWindow, float delta);
    virtual void updatePosition(float tx, float ty) override;
    void updateScale(float scaleX, float scaleY);
    sf::Sprite& getSprite();
private:
    SpriteObject spriteObj = SpriteObject();
    std::queue<sf::Texture>& textures_;
    bool putNext();
};

#endif
