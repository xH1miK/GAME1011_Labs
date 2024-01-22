#include "Game.h"

Game::Game(const std::string& name, const std::string& publisher, const std::string& developer)
    : name(name), publisher(publisher), developer(developer) {}

Game::~Game() {
    for (auto achievement : achievements) {
        delete achievement;
    }
}

void Game::addAchievement(Achievement* achievement) {
    achievements.push_back(achievement);
}

const std::vector<Achievement*>& Game::getAchievements() const {
    return achievements;
}


