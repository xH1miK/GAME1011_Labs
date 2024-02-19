#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Weapon {
public:
    string name;
    int damage;
    vector<string> specialAbilities;

    Weapon(string name, int damage, vector<string> specialAbilities) : name(name), damage(damage), specialAbilities(specialAbilities) {}

    friend ostream& operator<<(ostream& os, const Weapon& w) {
        os << "Weapon: " << w.name << ", Damage: " << w.damage << ", Special Abilities: ";
        for (const auto& ability : w.specialAbilities) os << ability << " ";
        return os;
    }

    bool operator==(const Weapon& other) const {
        return name == other.name && damage == other.damage && specialAbilities == other.specialAbilities;
    }
};

class Armour {
public:
    string name;
    string description;
    int armourValue;

    Armour(string name, string description, int armourValue) : name(name), description(description), armourValue(armourValue) {}

    friend ostream& operator<<(ostream& os, const Armour& a) {
        os << "Armour: " << a.name << ", Description: " << a.description << ", Armour Value: " << a.armourValue;
        return os;
    }

    bool operator==(const Armour& other) const {
        return name == other.name && description == other.description && armourValue == other.armourValue;
    }
};

class Character {
public:
    string name;
    string species;
    string epicBackstory;
    int startingHealth;
    shared_ptr<Weapon> weapon;
    shared_ptr<Armour> armour;

    Character(string name, string species, string epicBackstory, int startingHealth, shared_ptr<Weapon> weapon, shared_ptr<Armour> armour)
        : name(name), species(species), epicBackstory(epicBackstory), startingHealth(startingHealth), weapon(weapon), armour(armour) {}

    void displayCharacterInfo() const {
        cout << "Name: " << name << "\nSpecies: " << species << "\nEpic Backstory: " << epicBackstory
            << "\nStarting Health: " << startingHealth << "\n" << *weapon << "\n" << *armour << endl;
    }
};