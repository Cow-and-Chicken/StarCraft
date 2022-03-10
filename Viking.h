#include "Abilities.h"

struct Viking{
    int hp;
};

void attackViking(Ship *attacker,Ship *attacked);
void getDMGViking(Ship *ship,int dmg);
void specialAbilityViking(Ship *ship);
Abilities createVikingAbilities(void);