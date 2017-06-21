//
// Created by cilan on 5/25/2017.
//

#include "RectangleObject.h"

void RectangleObject::update() {
    _x = this->getShape().getPosition().x;
    _y = this->getShape().getPosition().y;
    width = this->getShape().getGlobalBounds().width;
    height = this->getShape().getGlobalBounds().height;
    _sX = this->getShape().getScale().x;
    _sY = this->getShape().getScale().y;
}

void RectangleObject::update(sf::Texture* texture) {
    shape_->update(texture);
    this->update();
}

RectangleObject::RectangleObject() {
    shapeObj.update(this->shape_->shape);
}

void RectangleObject::updateScale(float scaleX, float scaleY) {
    this->shapeObj.updateScale(scaleX, scaleY);
    this->update();
}

void RectangleObject::updatePosition(float tx, float ty) {
    this->shapeObj.updatePosition(tx, ty);
    this->update();
}

void RectangleObject::updateFillColor(const sf::Color& color) {
    this->shapeObj.updateFillColor(color);
}

void RectangleObject::updateOutlineColor(const sf::Color& color) {
    this->shapeObj.updateOutlineColor(color);
}

void RectangleObject::updateOutlineThickness(float thickness) {
    this->shapeObj.updateOutlineThickness(thickness);
}

void RectangleObject::updateSize(float width, float height) {
    this->getShape().setSize(sf::Vector2f(width, height));
    this->update();
}

bool RectangleObject::update(sf::RenderWindow& gWindow, sf::Event& event, uint16_t delta) {
    if (delta) {
        render_->update(gWindow, drawableComponents);
    }
    return true;
}

sf::RectangleShape& RectangleObject::getShape() {
    return shape_->shape;
}
