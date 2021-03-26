#ifndef BATTLECRUSER_H_
#define BATTLECRUSER_H_

#include "Abilities.h"

struct BattleCruser{
    int hp;
    unsigned short round;
};

void attackCruser(Ship *attacker,Ship *attacked);
void getDMGCruser(Ship *ship,int dmg);
void specialAbilityCruser(Ship *ship);
Abilities createCruserAbilities(void);

#endif /* BATTLECRUSER_H_ */