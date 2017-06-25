//
// Created by cilan on 3/15/2017.
//

#include "Scene.h"

Scene::Scene() {
    YAML::Node& config = Locator::currentConfig;
    this->width = config["video"]["width"].as<uint16_t>();
    this->height = config["video"]["height"].as<uint16_t>();
    this->fullscreen = config["video"]["fullscreen"].as<bool>();
}

bool Scene::updateObjects(sf::RenderWindow& window, sf::Event& event, uint16_t delta = 0) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        const std::shared_ptr<GameObject>& object = gameObjects.at(i);
        if (!object->update(window, event, delta)) return false;
    }
    return true;
}

void Scene::loop(sf::RenderWindow& window) {
    if (!window.isOpen()) {
        window.create(sf::VideoMode(this->width, this->height), "I Am Synthetic", fullscreen ? sf::Style::Fullscreen
                                                                                 : sf::Style::Close);
        window.requestFocus();
    }
    bool active = true;
    while (window.isOpen()) {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event)) {
            do {
                switch (event.type) {
                    case sf::Event::GainedFocus:
                        active = true;
                        break;
                    case sf::Event::LostFocus:
                        active = false;
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape) {
                            if (this->fullscreen) {
                                this->fullscreen = false;
                                window.create(sf::VideoMode(width, height), "I Am Synthetic",
                                              sf::Style::Close);
                            }
                        }
                        break;
                    default:
                        break;
                }
                if (!updateObjects(window, event)) return;
            } while (!active && window.waitEvent(event));
        }
        updateObjects(window, event, 10); // 10 is delta
        window.display();
    }
}
