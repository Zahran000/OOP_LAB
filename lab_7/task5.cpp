#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public:
    Character(string id, string n, int lvl, int hp, string weapon) 
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}
    
    virtual void attack() {
        cout << name << " attacks with " << weaponType << endl;
    }
    
    virtual void defend() {
        cout << name << " defends with basic stance" << endl;
    }
    
    virtual void displayStats() {
        cout << "ID: " << characterID << "\nName: " << name << "\nLevel: " << level 
             << "\nHP: " << healthPoints << "\nWeapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage) 
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}
    
    void attack() override {
        cout << name << " swings " << weaponType << " for " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int lvl, int hp, string weapon, int mana, int power) 
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}
    
    void defend() override {
        cout << name << " creates a magical barrier using " << manaPoints << " mana" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) 
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}
    
    void attack() override {
        if (arrowCount > 0) {
            cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy (" << --arrowCount << " left)" << endl;
        } else {
            cout << name << " is out of arrows!" << endl;
        }
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int lvl, int hp, string weapon, int stealth, int agi) 
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}
    
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior tipu("W001", "Tipu Sultan", 10, 150, "Scimitar", 50, 35);
    Mage jinnah("M001", "Allama Jinnah", 8, 80, "Staff", 100, 60);
    Archer razia("A001", "Razia Sultana", 12, 110, "Longbow", 20, 85);
    Rogue bhutto("R001", "Bhutto the Shadow", 15, 95, "Daggers", 90, 95);
    
    tipu.attack();
    tipu.displayStats();
    cout << endl;
    
    jinnah.defend();
    jinnah.displayStats();
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        razia.attack();
    }
    razia.displayStats();
    cout << endl;
    
    bhutto.displayStats();
    bhutto.attack();
    
    return 0;
}
