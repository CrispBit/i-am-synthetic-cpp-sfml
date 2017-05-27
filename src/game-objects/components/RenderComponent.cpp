#include "RenderComponent.h"

RenderComponent::RenderComponent() {
    // do nothing
}

void RenderComponent::update(sf::RenderWindow& window, std::vector<std::weak_ptr<DrawableComponent>>& components) {
    for (std::weak_ptr<DrawableComponent> const& component : components) {
       if (auto spt = component.lock()) {
           spt->draw(window);
       }
    } 
}
