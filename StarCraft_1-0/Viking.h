#ifndef VIKING_H_
#define VIKING_H_

#include "List.h"



void attackViking(Ship *attacker,Ship *attacked);
void getDMGViking(Ship *ship,int dmg);
void specialAbilityViking(Ship *ship);
Abilities createVikingAbilities(void);

#endif /* VIKING_H_ */