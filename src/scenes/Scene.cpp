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

bool Scene::updateButtons(sf::Event event, sf::RenderWindow &window) {
    bool stay = true;
    for (std::shared_ptr<Button> button : buttons) {
        if (!button->update(event, window)) stay = false;
    }
    return stay;
}

void Scene::updateObjects(sf::RenderWindow& window) {
    for (std::shared_ptr<GameObject> object : gameObjects) {
        object->update(window);
    }
}

void Scene::loop(sf::RenderWindow& window) {
    if (!window.isOpen()) {
        window.create(sf::VideoMode(width, height), "I Am Synthetic", sf::Style::Default |
                (fullscreen ? sf::Style::Fullscreen : 0));
        window.requestFocus();
    }
    bool active = true;
    while (window.isOpen()) {
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
                                              sf::Style::Titlebar + sf::Style::Close);
                            }
                        }
                        break;
                    default:
                        handleEvent(event);
                        if (!updateButtons(event, window)) return;
                }
            } while (!active && window.waitEvent(event));
        }
        draw(window);
    }
}

void Scene::draw(sf::RenderWindow& window)  {
    window.clear();
    for (std::shared_ptr<Button> button : buttons) {
        window.draw(*button);
    }
    sDraw(window);
    updateObjects(window);
    window.display();
}
