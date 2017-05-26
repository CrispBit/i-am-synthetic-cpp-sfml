//
// Created by cilan on 3/18/2017.
//

#ifndef I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H
#define I_AM_SYNTHETIC_C_SFML_CHAPTERSELECTSCENE_H

#include "Scene.h"
#include <string>
#include <memory>
#include "../Data.h"
#include "../buttons/FileAddButton.h"

class PlayScene : public Scene {
public:
    PlayScene();
protected:
    std::vector<std::shared_ptr<Button>> fileButtons = {};
    bool updateButtons(sf::Event event, sf::RenderWindow &window) override;
    void sDraw(sf::RenderWindow& window) override;
};

#endif
