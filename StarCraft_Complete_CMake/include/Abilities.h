#ifndef ABILITIES_H_
#define ABILITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"

/* StarShip Abilities */
struct Abilities{

   /* Calculating the exact amount of damage this ship is going to deal 
      and passing it to the getDMG function of the ship it is attacking */
   int (*attack)(Ship *attacker, List *targetFleet);

   /* Function called in the attackShip function of the attacker that tells 
      how much damage it dealt so this function can decrement the needed values; 
      Returns if ship is destroyed*/
   int (*getDMG)(Ship *ship, int dmg);

   /* Activates the special ability of the ship */
   void (*specialAbility)(Ship *ship);

   /* Prints the ship type */
   void (*printShip)(void);
};

#endif /* ABILITIES_H_ */
