#include <iostream>
#include "RPG.h"
using namespace std;

void gameLoop(RPG* p1, RPG* p2);
void displayEnd(const RPG& p1, const RPG& p2);
void displayStats(const RPG& p);

int main() {
    RPG p1("wiz", 70, 45, 15, "mage");
    RPG p2;

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}

void displayStats(const RPG& p) {
    cout << p.getName() << " Health: " << p.getHealth() << endl;
}

void displayEnd(const RPG& p1, const RPG& p2) {
    cout << "Game Over" << endl;
    if(p1.isAlive() && !p2.isAlive()) {
        cout << p1.getName() << " wins" << endl;
    } else if (!p1.isAlive() && p2.isAlive()) {
        cout << p2.getName() << " wins" << endl;
    } else if (!p1.isAlive() && !p2.isAlive()) {
        cout << "It's a tie!" << endl;
    }
}

void gameLoop(RPG* p1, RPG* p2) {
    while (p1->isAlive() && p2->isAlive()) {
        displayStats(*p1);
        cout << p1->getName() << " It's your turn" << endl;
        p1->useSkill(p2);
        cout << "-------------------------------" << endl;

        if (p2->isAlive()) {
            displayStats(*p2);
            cout << p2->getName() << " It's your turn" << endl;
            p2->useSkill(p1);
            cout << "-------------------------------" << endl;
        }
    }
}
