//
// Created by cilan on 5/25/2017.
//

#include "ShapeObject.h"

void ShapeObject::update() {
    _x = this->getShape().getPosition().x;
    _y = this->getShape().getPosition().y;
    width = this->getShape().getGlobalBounds().width;
    height = this->getShape().getGlobalBounds().height;
    _sX = this->getShape().getScale().x;
    _sY = this->getShape().getScale().y;
}

void ShapeObject::update(sf::Shape& shape) {
    shape_->update(shape);
    this->update();
}

void ShapeObject::updateFillColor(const sf::Color& color) {
    this->getShape().setFillColor(color);
}

void ShapeObject::updateOutlineColor(const sf::Color& color) {
    this->getShape().setOutlineColor(color);
}

void ShapeObject::updateOutlineThickness(float thickness) {
    this->getShape().setOutlineThickness(thickness);
    this->update();
}

ShapeObject::ShapeObject() {
    // do nothing
}

ShapeObject::ShapeObject(sf::Shape& shape) {
    this->update(shape);
}

void ShapeObject::updateScale(float scaleX, float scaleY) {
    this->getShape().setScale(scaleX, scaleY);
    this->update();
}

void ShapeObject::updatePosition(float tx, float ty) {
    this->getShape().setPosition(tx, ty);
    this->update();
}

bool ShapeObject::update(sf::RenderWindow& gWindow, sf::Event& event, uint16_t delta) {
    if (delta) {
        render_->update(gWindow, drawableComponents);
    }
    return true;
}

sf::Shape& ShapeObject::getShape() {
    return *shape_->shape;
}
