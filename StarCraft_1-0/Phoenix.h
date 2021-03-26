#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "List.h"



void attackPhoenix(Ship *attacker,Ship *attacked);
void getDMGPhoenix(Ship *ship,int dmg);
void specialAbilityPhoenix(Ship *ship);
Abilities createPhoenixAbilities(void);

#endif /* PHOENIX_H_ */