#ifndef SHIP_H_
#define SHIP_H_

#include "Abilities.h"

/* Creates the BattleCruser struct */
struct BattleCruser
{
    int hp;
    unsigned short round;
};

/* Creates the Viking struct */
struct Viking
{
    int hp;
};

/* Creates the Phoenix struct */
struct Phoenix
{
    int hp;
    int shield;
};

/* Creates the Carrier struct */
struct Carrier
{
    int hp;
    int shield;
    unsigned short drones;
};

/* Creates the union that encompasses all ship types */
union Ships
{
    Carrier carrier;
    Phoenix phoenix;
    Viking viking;
    BattleCruser battleCruser;
};

/* "Assemles" a complete ship */
struct Ship
{
    /*Ship abilities*/
    Abilities abilities;
    /*Ship stats: hp, shield...*/
    Ships ships;
    /*Prints the ship status*/
    void (*printShipStatus)(Ship *ship);
    /*Type of ship*/
    AirShipType type;
};

Ship createCruser(void);
Ship createViking(void);
Ship createPhoenix(void);
Ship createCarrier(void);

#endif /* SHIP_H_ */