#ifndef SHIP_H_
#define SHIP_H_

#include "Abilities.h"

/* Creates the BattleCruser struct */
struct BattleCruser
{
    Ship1 ship;

    unsigned short round;
};
typedef int shield;
/* Creates the Viking struct */
struct Viking
{
    Ship1 ship;
};

/* Creates the Phoenix struct */
struct Phoenix
{
    shipProttos ship;
};

/* Creates the Carrier struct */
struct Carrier
{
    shipProttos ship;
    unsigned short drones;
};

typedef struct Ship1{
    int hp;
} Ship1;

typedef struct shipProttos{
    int shield;
    Ship1 hp;
}shipProttos;

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