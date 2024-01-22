#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Achievement.h"

class Game {
private:
    std::string name;
    std::string publisher;
    std::string developer;
    std::vector<Achievement*> achievements;

public:
    Game(const std::string& name, const std::string& publisher, const std::string& developer);
    ~Game();

    void addAchievement(Achievement* achievement);
    const std::vector<Achievement*>& getAchievements() const;
    std::string getName() const { return name; }
    std::string getPublisher() const { return publisher; }
    std::string getDeveloper() const { return developer; }
};

#endif

