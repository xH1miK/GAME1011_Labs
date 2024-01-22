#include "Platform.h"

Platform::Platform(const std::string& name, const std::string& manufacturer)
    : name(name), manufacturer(manufacturer) {}

Platform::~Platform() {
    for (auto game : games) {
        delete game;
    }
}

void Platform::addGame(Game* game) {
    games.push_back(game);
}

const std::vector<Game*>& Platform::getGames() const {
    return games;
}
