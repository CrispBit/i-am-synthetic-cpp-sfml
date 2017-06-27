//
// Created by cilan on 5/25/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_RECTANGLEOBJECT_H
#define I_AM_SYNTHETIC_C_SFML_RECTANGLEOBJECT_H

#include <SFML/Window.hpp>
#include "ShapeObject.h"
#include "components/RectangleComponent.h"
#include "components/DrawableComponent.h"
#include "components/RenderComponent.h"

class RectangleObject : public GameObject {
public:
    RectangleObject();
    virtual bool update(sf::RenderWindow& gWindow, sf::Event& event) { return true; };
    virtual void render(sf::RenderWindow& gWindow, float delta);
    void update(sf::Texture* shape);
    virtual void updatePosition(float tx, float ty) override;
    void updateFillColor(const sf::Color& color);
    void updateOutlineColor(const sf::Color& color);
    void updateOutlineThickness(float thickness);
    void updateScale(float scaleX, float scaleY);
    void updateSize(float width, float height);
    sf::RectangleShape& getShape();
private:
    std::shared_ptr<RectangleComponent> shape_ = std::make_shared<RectangleComponent>();
    std::shared_ptr<RenderComponent> render_ = std::make_shared<RenderComponent>();
    ShapeObject shapeObj;
    std::vector<std::weak_ptr<DrawableComponent>> drawableComponents = {shape_};
protected:
    std::vector<std::shared_ptr<Component>> components = {shape_, render_};
    virtual void update() override;
};

#endif
