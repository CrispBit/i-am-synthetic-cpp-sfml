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

bool Scene::updateObjects(sf::RenderWindow& gWindow, sf::Event& event) {
    for (unsigned int i = 0; i < gameObjects.size(); i++) {
        const std::shared_ptr<GameObject>& object = gameObjects.at(i);
        if (!object->update(gWindow, event)) return false;
    }
    return true;
}

void Scene::renderObjects(sf::RenderWindow& window, float delta) {
    for (std::shared_ptr<GameObject>& object : gameObjects) {
        object->render(window, delta);
    }
}

void Scene::loop(sf::RenderWindow& window) {
    if (!window.isOpen()) {
        window.create(sf::VideoMode(this->width, this->height), "I Am Synthetic", fullscreen ? sf::Style::Fullscreen
                                                                                 : sf::Style::Close);
        window.requestFocus();
        window.setFramerateLimit(Locator::currentConfig["video"]["fps"].as<unsigned int>());
    }
    bool active = true;

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        window.clear();
        sf::Event event;
        while (timeSinceLastUpdate >= timePerFrame) {
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
                                    window.create(sf::VideoMode(width, height), "I Am Synthetic", sf::Style::Close);
                                }
                            }
                            break;
                        default:
                            break;
                    }
                    if (!updateObjects(window, event)) return;
                } while (!active && window.waitEvent(event));
            }
            timeSinceLastUpdate -= timePerFrame;
        }
        renderObjects(window, elapsedTime.asSeconds());
        window.display();
    }
}
