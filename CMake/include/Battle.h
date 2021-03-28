#ifndef BATTLE_H_
#define BATTLE_H_

#include "Viking.h"
#include "Phoenix.h"
#include "Carrier.h"
#include "BattleCruser.h"

void battle(void);
int processTurn(List *attackingFleet, List *targetFleet);
void printShip(Ship *ship, int shipIndex);
void printVictory(enum Victory victoryFlag);
void generateTerranFleet(List *terranFleet);
void generateProtossFleet(List *protossFleet);
void shipDestoyed(Ship *ship, int shipIndex, int targetIndex);

#endif /* BATTLE_H_ */