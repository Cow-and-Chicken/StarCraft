#ifndef ABILITIES_H_
#define ABILITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"

struct Abilities{
    int (*attack)(Ship *attacker,List *targetFleet);
    int (*getDMG)(Ship *ship,int dmg);
    void (*specialAbility)(Ship *ship);
    void (*printShip)(void);
};

#endif /* ABILITIES_H_ */