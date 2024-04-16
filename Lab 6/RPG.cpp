#include "RPG.h"
#include <iostream> 

RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();
}

string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

void RPG::setSkills() {
    if (type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(string skill, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

void RPG::updateHealth(int new_health) {
    health = new_health;
}

bool RPG::isAlive() const {
    return health > 0;
}

void RPG::attack(RPG* opponent) {
    int damage = strength - opponent->getDefense();
    if (damage < 0) damage = 0;
    int newHealth = opponent->getHealth() - damage;
    opponent->updateHealth(newHealth);
}

void RPG::useSkill(RPG* opponent) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }
    int chosen_skill_index;
    cout << "Choose a skill to use: Enter 0 or 1\n";
    cin >> chosen_skill_index;
    string chosen_skill = skills[chosen_skill_index];
    printAction(chosen_skill, *opponent);
    attack(opponent);
}
