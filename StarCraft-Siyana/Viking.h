#ifndef VIKING_H_
#define VIKING_H_

#include "List.h"

int attackViking(Ship *attacker,List *targetFleet);
int getDMGViking(Ship *ship,int dmg);
void specialAbilityViking(Ship *ship);
void printVikingStatus(Ship *ship);
void printViking(Ship *ship);
Abilities createVikingAbilities(void);

#endif /* VIKING_H_ */