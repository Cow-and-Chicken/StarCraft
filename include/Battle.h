#include "../include/Viking.h"
#include "../include/Phoenix.h"
#include "../include/Carrier.h"
#include "../include/BattleCruser.h"

void battle(void);
int processTurn(List *attackingFleet, List *targetFleet);
void printShip(Ship *ship, int shipIndex);
void printVictory(enum Victory victoryFlag);
void generateTerranFleet(List *terranFleet);
void generateProtossFleet(List *protossFleet);
void shipDestoyed(Ship *ship, int shipIndex, int targetIndex);
