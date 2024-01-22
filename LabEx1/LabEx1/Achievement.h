#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>

class Achievement {
private:
    std::string title;
    std::string description;
    int scoreValue;

public:
    Achievement(const std::string& title, const std::string& description, int scoreValue);

    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
    int getScore() const { return scoreValue; }
};

#endif


