//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_SPRITEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_SPRITEOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/SpriteComponent.h"
#include "components/DrawableComponent.h"
#include "components/RenderComponent.h"

class SpriteObject : public GameObject {
public:
    SpriteObject(sf::Texture& texture);
    virtual void update(sf::RenderWindow& gWindow);
    void update(sf::Texture& texture);
    sf::Sprite& getSprite();
private:
    std::shared_ptr<SpriteComponent> sprite_ = std::make_shared<SpriteComponent>();
    std::shared_ptr<RenderComponent> render_ = std::make_shared<RenderComponent>();
    std::vector<std::weak_ptr<DrawableComponent>> drawableComponents = {sprite_};
protected:
    std::vector<std::shared_ptr<Component>> components = {sprite_, render_};
};

#endif
