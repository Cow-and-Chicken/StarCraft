#ifndef ABILITIES_H_
#define ABILITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"

struct Abilities{
    void (*attack)(Ship *attacker,Ship *attacked);
    void (*getDMG)(Ship *ship,int dmg);
    void (*specialAbility)(Ship *ship);
};

#endif /* ABILITIES_H_ */
