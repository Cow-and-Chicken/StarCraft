#include "List.h"

void battle(void);
int processTurn(List *attackingFleet, List *targetFleet);
void printShip(Ship *ship, int shipIndex);
void printVictory(enum Victory victoryFlag);
int checkTarget(Ship *ship);
List *generateTerranFleet(void);
List *generateProtossFleet(void);
void shipDestoyed(Ship *ship, int shipIndex, int targerIndex);
void printTerranShip(Ship *ship, int shipIndex);
void printProtossShip(Ship *ship, int shipIndex);

