#ifndef BATTLECRUSER_H_
#define BATTLECRUSER_H_

#include "List.h"

int attackCruser(Ship *attacker,List *targetFleet);
int getDMGCruser(Ship *ship,int dmg);
void specialAbilityCruser(Ship *ship);
void printCruserStatus(Ship *ship);
void printCruser(void);
Abilities createCruserAbilities(void);

#endif /* BATTLECRUSER_H_ */