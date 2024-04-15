#include <iostream>
#include "RPG.h"
using namespace std;

int main(){
   
    RPG rpg1;
    RPG rpg2("Player", 150, 20, 15, "mage"); 

    
    cout << "RPG1 is alive: " << rpg1.isAlive() << endl; 
    cout << "RPG2 is alive: " << rpg2.isAlive() << endl; 

    
    rpg1.updateHealth(0); 
    rpg2.updateHealth(10); 

    cout << "After update:" << endl;
    cout << "RPG1 is alive: " << rpg1.isAlive() << endl; 
    cout << "RPG2 is alive: " << rpg2.isAlive() << endl; 

    
    cout << "RPG1 health: " << rpg1.getHealth() << endl; 
    cout << "RPG2 health: " << rpg2.getHealth() << endl; 
    return 0;
}