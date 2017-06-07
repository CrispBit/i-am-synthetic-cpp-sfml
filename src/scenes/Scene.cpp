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

bool Scene::updateObjects(sf::RenderWindow& window, sf::Event::EventType& event, uint16_t delta = 0) {
    bool stay = true;
    for (std::shared_ptr<GameObject> object : gameObjects) {
        if (!object->update(window, event, delta)) stay = false;
    }
    return stay;
}

void Scene::loop(sf::RenderWindow& window) {
    if (!window.isOpen()) {
        window.create(sf::VideoMode(width, height), "I Am Synthetic", sf::Style::Titlebar | sf::Style::Close |
                (fullscreen ? sf::Style::Fullscreen : 0));
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
                                              sf::Style::Titlebar | sf::Style::Close);
                            }
                        }
                        break;
                    default:
                        break;
                }
                handleEvent(event.type);
                if (!updateObjects(window, event.type)) return;
            } while (!active && window.waitEvent(event));
        }
        updateObjects(window, event.type, 10); // 10 is delta
        window.display();
    }
}
