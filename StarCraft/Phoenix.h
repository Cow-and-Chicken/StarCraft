#include "Abilities.h"

struct Phoenix{
    int hp;
    int shield;
};

void attackPhoenix(Ship *attacker,Ship *attacked);
void getDMGPhoenix(Ship *ship,int dmg);
void specialAbilityPhoenix(Ship *ship);
Abilities createPhoenixAbilities(void);
