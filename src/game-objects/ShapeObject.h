//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_SHAPEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_SHAPEOBJECT_H

#include <SFML/Window.hpp>
#include "GameObject.h"
#include "components/ShapeComponent.h"
#include "components/DrawableComponent.h"
#include "components/RenderComponent.h"

class ShapeObject : public GameObject {
public:
    ShapeObject();
    ShapeObject(sf::Shape& shape);
    virtual bool update(sf::RenderWindow& gWindow, sf::Event& event, uint16_t delta) override;
    void update(sf::Shape& shape);
    virtual void updatePosition(float tx, float ty) override; 
    void updateScale(float scaleX, float scaleY);
    void updateFillColor(const sf::Color& color);
    void updateOutlineColor(const sf::Color& color);
    void updateOutlineThickness(float thickness);
    sf::Shape& getShape();
private:
    std::shared_ptr<ShapeComponent> shape_ = std::make_shared<ShapeComponent>();
    std::shared_ptr<RenderComponent> render_ = std::make_shared<RenderComponent>();
    std::vector<std::weak_ptr<DrawableComponent>> drawableComponents = {shape_};
protected:
    std::vector<std::shared_ptr<Component>> components = {shape_, render_};
    virtual void update() override;
};

#endif
