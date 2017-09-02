#ifndef synthy_h
#define synthy_h

#include "crispsynth/Game.h"
#include "scenes/MainMenuScene.h"
#include "scenes/LevelScene.h"
#include "scenes/PlayScene.h"
#include "scenes/CreditsScene.h"

class PlayScene;

class Synthy : public Game {
public:
    Synthy(sf::RenderWindow &window);
    std::shared_ptr<Scene> mainMenuScene;
    std::shared_ptr<PlayScene> playScene;
    std::shared_ptr<Scene> creditsScene;
};

#endif
