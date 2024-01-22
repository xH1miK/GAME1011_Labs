#include <iostream>
#include <vector>
#include <tuple>
#include "Platform.h"
#include "Game.h"
#include "Achievement.h"

void addGameToPlatform(Platform* platform) {
    std::string name, publisher, developer;
    std::cout << "Enter game name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter game publisher: ";
    std::getline(std::cin >> std::ws, publisher);
    std::cout << "Enter game developer: ";
    std::getline(std::cin >> std::ws, developer);

    if (platform->getGames().size() < 5) {
        Game* game = new Game(name, publisher, developer);
        platform->addGame(game);
        std::cout << "Game added to platform.\n";
    }
    else {
        std::cout << "Maximum number of games reached for this platform.\n";
    }
}

void addAchievementToGame(Game* game) {
    std::string title, description;
    int score;
    std::cout << "Enter achievement name: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter achievement description: ";
    std::getline(std::cin >> std::ws, description);
    std::cout << "Enter achievement score: ";
    std::cin >> score;

    if (game->getAchievements().size() < 5) {
        Achievement* achievement = new Achievement(title, description, score);
        game->addAchievement(achievement);
        std::cout << "Achievement added to game.\n";
    }
    else {
        std::cout << "Maximum number of achievements reached for this game.\n";
    }
}

void viewPlatforms(const std::vector<Platform*>& platforms) {
    if (platforms.empty()) {
        std::cout << "No platforms available.\n";
    }
    else {
        for (const auto& platform : platforms) {
            std::cout << "Platform: " << platform->getName() << ", Manufacturer: " << platform->getManufacturer() << "\n";
        }
    }
}

void viewGames(const Platform* platform) {
    const auto& games = platform->getGames();
    if (games.empty()) {
        std::cout << "No games available on this platform.\n";
    }
    else {
        for (const auto& game : games) {
            std::cout << "Game: " << game->getName() << ", Publisher: " << game->getPublisher() << ", Developer: " << game->getDeveloper() << "\n";
        }
    }
}

void viewAchievements(const Game* game) {
    const auto& achievements = game->getAchievements();
    if (achievements.empty()) {
        std::cout << "No achievements available for this game.\n";
    }
    else {
        for (const auto& achievement : achievements) {
            std::cout << "Achievement: " << achievement->getTitle() << ", Description: " << achievement->getDescription() << ", Score: " << achievement->getScore() << "\n";
        }
    }
}

int main() {
    std::vector<Platform*> platforms;
    
    std::vector<std::pair<std::string, std::string>> platformData = {
        {"Xbox", "Microsoft"},
        {"PS", "Sony"},
        {"Windows", "Microsoft"},
        {"macOS", "Apple"},
        {"IOS", "Apple"}
    };

    std::vector<std::tuple<std::string, std::string, std::string>> gameData = {
        std::make_tuple("GTA:V", "Rockstar Games", "Rockstar Games"),
        std::make_tuple("Rainbow Six Siege", "Ubisoft", "Ubisoft"),
        std::make_tuple("RDR2", "Rockstar Games", "Rockstar Games"),
        std::make_tuple("Fortnite", "Epic Games", "Epic Games"),
        std::make_tuple("Dota2", "Valve", "Valve")
    };

    std::vector<std::tuple<std::string, std::string, int>> achievementData = {
        std::make_tuple("Gunslinger", "Kill 5 players with 1 shot", 150),
        std::make_tuple("Car enjoyer", "Drive 100 miles by car", 250),
        std::make_tuple("Western boy", "Buy your first revolver", 100),
        std::make_tuple("KFC Fan", "Eat chicken", 50),
        std::make_tuple("Finders Keepers", "Find 1 treasure chest", 500)
    };

    for (const auto& p : platformData) {
        Platform* platform = new Platform(p.first, p.second);
        platforms.push_back(platform);

        for (const auto& g : gameData) {
            Game* game = new Game(std::get<0>(g), std::get<1>(g), std::get<2>(g));
            platform->addGame(game);

            for (const auto& a : achievementData) {
                Achievement* achievement = new Achievement(std::get<0>(a), std::get<1>(a), std::get<2>(a));
                game->addAchievement(achievement);
            }
        }
    }
    
    int choice;

    while (true) {
        std::cout << "1. Create platform\n";
        std::cout << "2. Add game to platform\n";
        std::cout << "3. Add achievement to game\n";
        std::cout << "4. View platforms\n";
        std::cout << "5. View games on a platform\n";
        std::cout << "6. View achievements in a game\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, manufacturer;
            std::cout << "Enter platform name: ";
            std::getline(std::cin >> std::ws, name);
            std::cout << "Enter platform manufacturer: ";
            std::getline(std::cin >> std::ws, manufacturer);

            Platform* platform = new Platform(name, manufacturer);
            platforms.push_back(platform);
            std::cout << "Platform created.\n";
            break;
        }
        case 2: {
            if (platforms.empty()) {
                std::cout << "Create platform first.\n";
                break;
            }
            addGameToPlatform(platforms[0]);
            break;
        }
        case 3: {
            if (platforms.empty() || platforms[0]->getGames().empty()) {
                std::cout << "Create game first.\n";
                break;
            }
            addAchievementToGame(platforms[0]->getGames()[0]);
            break;
        }
        case 4:
            viewPlatforms(platforms);
            break;
        case 5: {
            if (platforms.empty()) {
                std::cout << "Create platform first.\n";
                break;
            }
            viewGames(platforms[0]);
            break;
        }
        case 6: {
            if (platforms.empty() || platforms[0]->getGames().empty()) {
                std::cout << "Create game first.\n";
                break;
            }
            viewAchievements(platforms[0]->getGames()[0]);
            break;
        }
        case 7:
            for (auto platform : platforms) {
                delete platform;
            }
            return 0;
        default:
            std::cout << "Wrong. Try again.\n";
        }
    }

    for (auto platform : platforms) {
        delete platform;
    }

    return 0;
}


