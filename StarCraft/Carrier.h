#include "Abilities.h"

struct Carrier{
    int hp;
    int shield;
    unsigned short drones;
};

void attackCarrier(Ship *attacker,Ship *attacked);
void getDMGCarrier(Ship *ship,int dmg);
void droneCheckCarrier(Ship *ship);
void specialAbilityCarrier(Ship *ship);
Abilities createCarrierAbilities(void);
