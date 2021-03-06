#ifndef CARRIER_H_
#define CARRIER_H_

#include "List.h"



int attackCarrier(Ship *attacker,List *targetFleet);
int getDMGCarrier(Ship *ship,int dmg);
void specialAbilityCarrier(Ship *ship);
void printCarrierStatus(Ship *ship);
void printCarrier(void);
void droneCheckCarrier(Ship *ship);
Abilities createCarrierAbilities(void);

#endif /* CARRIER_H_ */