#ifndef SHIP_H_
#define SHIP_H_

#include "../include/Abilities.h"

struct BattleCruser{
    int hp;
    unsigned short round;
};

struct Viking{
    int hp;
};

struct Phoenix{
    int hp;
    int shield;
};

struct Carrier{
    int hp;
    int shield;
    unsigned short drones;
};

union Ships{
    Carrier carrier;
    Phoenix phoenix;
    Viking viking;
    BattleCruser battleCruser;
};

struct Ship{
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