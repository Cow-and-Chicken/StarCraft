#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "List.h"



int attackPhoenix(Ship *attacker,List *targetFleet);
int getDMGPhoenix(Ship *ship,int dmg);
void specialAbilityPhoenix(Ship *ship);
void printPhoenixStatus(Ship *ship);
void printPhoenix(Ship *ship);
Abilities createPhoenixAbilities(void);

#endif /* PHOENIX_H_ */