//
// Created by cilan on 5/25/2017.
//

#include "ShapeObject.h"

void ShapeObject::update() {
    _x = this->getShape()->getPosition().x;
    _y = this->getShape()->getPosition().y;
    width = this->getShape()->getGlobalBounds().width;
    height = this->getShape()->getGlobalBounds().height;
    _sX = this->getShape()->getScale().x;
    _sY = this->getShape()->getScale().y;
}

void ShapeObject::update(std::unique_ptr<sf::Shape> shape) {
    shape_->update(std::move(shape));
    this->update();
}

ShapeObject::ShapeObject() {
    // do nothing
}

ShapeObject::ShapeObject(std::unique_ptr<sf::Shape> shape) {
    this->update(std::move(shape));
}

void ShapeObject::updateScale(float scaleX, float scaleY) {
    this->getShape()->setScale(scaleX, scaleY);
    this->update();
}

void ShapeObject::updatePosition(float tx, float ty) {
    this->getShape()->setPosition(tx, ty);
    this->update();
}

bool ShapeObject::update(sf::RenderWindow& gWindow, sf::Event::EventType& event, uint16_t delta) {
    if (delta) {
        render_->update(gWindow, drawableComponents);
    }
    return true;
}

std::unique_ptr<sf::Shape>& ShapeObject::getShape() {
    return shape_->shape;
}
