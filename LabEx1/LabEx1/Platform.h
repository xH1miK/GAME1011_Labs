#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <vector>
#include "Game.h"

class Platform {
private:
    std::string name;
    std::string manufacturer;
    std::vector<Game*> games;

public:
    Platform(const std::string& name, const std::string& manufacturer);
    ~Platform();

    void addGame(Game* game);
    const std::vector<Game*>& getGames() const;
    std::string getName() const { return name; }
    std::string getManufacturer() const { return manufacturer; }
};

#endif


