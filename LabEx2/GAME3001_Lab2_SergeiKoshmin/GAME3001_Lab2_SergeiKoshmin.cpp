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

    bool operator==(const Character& other) const {
        return name == other.name && species == other.species && *weapon == *other.weapon && *armour == *other.armour;
    }

};

vector<shared_ptr<Character>> characters;

shared_ptr<Weapon> chooseWeapon() {
    cout << "Choose a starting weapon:\n"
        << "1. Sword (Damage: 10, Special Abilities: Slice, Stab)\n"
        << "2. Bow (Damage: 8, Special Abilities: Quick Shot, Piercing Arrow)\n"
        << "3. Axe (Damage: 12, Special Abilities: Cleave, Sunder)\n"
        << "4. Staff (Damage: 6, Special Abilities: Magic Bolt, Heal)\n"
        << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        return make_shared<Weapon>("Sword", 10, vector<string>{"Slice", "Stab"});
    case 2:
        return make_shared<Weapon>("Bow", 8, vector<string>{"Quick Shot", "Piercing Arrow"});
    case 3:
        return make_shared<Weapon>("Axe", 12, vector<string>{"Cleave", "Sunder"});
    case 4:
        return make_shared<Weapon>("Staff", 6, vector<string>{"Magic Bolt", "Heal"});
    default:
        cout << "Invalid choice, defaulting to Sword." << endl;
        return make_shared<Weapon>("Sword", 10, vector<string>{"Slice", "Stab"});
    }
}

shared_ptr<Armour> chooseArmour() {
    cout << "Choose a starting armour set:\n"
        << "1. Chainmail (Armour Value: 50, Description: Strong chain links)\n"
        << "2. Leather (Armour Value: 30, Description: Lightweight and flexible)\n"
        << "3. Plate Armor (Armour Value: 70, Description: Heavy and protective)\n"
        << "4. Robes (Armour Value: 20, Description: Offers magical protection)\n"
        << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        return make_shared<Armour>("Chainmail", "Strong chain links.", 50);
    case 2:
        return make_shared<Armour>("Leather", "Lightweight and flexible.", 30);
    case 3:
        return make_shared<Armour>("Plate Armor", "Heavy and protective.", 70);
    case 4:
        return make_shared<Armour>("Robes", "Offers magical protection.", 20);
    default:
        cout << "Invalid choice, defaulting to Chainmail." << endl;
        return make_shared<Armour>("Chainmail", "Strong chain links.", 50);
    }
}


void createCharacter() {
    if (characters.size() >= 3) {
        cout << "Maximum number of characters created." << endl;
        return;
    }

    string name, species, epicBackstory;
    int startingHealth;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter character species: ";
    cin >> species;
    cout << "Enter character epic backstory: ";
    cin.ignore();
    getline(cin, epicBackstory);
    cout << "Enter starting health value (between 0 and 100): ";
    cin >> startingHealth;
    while (cin.fail() || startingHealth < 0 || startingHealth > 100) {
        cout << "Invalid input. Please enter a value between 0 and 100: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> startingHealth;
    }

    auto weapon = chooseWeapon();
    auto armour = chooseArmour();

    characters.push_back(make_shared<Character>(name, species, epicBackstory, startingHealth, weapon, armour));
    cout << "Character created successfully!" << endl;


}

void displayCharacters() {
    for (const auto& character : characters) {
        character->displayCharacterInfo();
        cout << "-----------------------------------" << endl;
    }
}

void compareCharacters() {
    if (characters.size() < 2) {
        cout << "Not enough characters to compare. Please create more characters." << endl;
        return;
    }

    int firstCharacterIndex, secondCharacterIndex;
    cout << "Enter the index of the first character to compare: ";
    cin >> firstCharacterIndex;
    cout << "Enter the index of the second character to compare: ";
    cin >> secondCharacterIndex;

    if (firstCharacterIndex < 1 || firstCharacterIndex > characters.size() || secondCharacterIndex < 1 || secondCharacterIndex > characters.size()) {
        cout << "Invalid character indexes. Please try again." << endl;
        return;
    }

    if (*characters[firstCharacterIndex - 1] == *characters[secondCharacterIndex - 1]) {
        cout << "Characters are the same." << endl;
    }
    else {
        cout << "Characters are different." << endl;
    }
}


int main() {
    cout << "Welcome to the Character Customizer!" << endl;

    int choice;
    do {
        cout << "1. Create a new character\n2. Display all characters\n3. Compare two characters\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            createCharacter();
            break;
        case 2:
            displayCharacters();
            break;
        case 3:
            compareCharacters();
            break;
        case 4:
            cout << "Exiting character customizer." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);


    return 0;
}