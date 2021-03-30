#include "Viking.h"

/* Calculating the exact amount of damage this ship is going to deal 
and passing it to the getDMG function of the ship it is attacking */
int attackViking(Ship *attacker, List *targetFleet)
{
    int dmg;
    Ship *target = getLast(targetFleet);
    if (target->type == PHOENIX)
    {
        dmg = VIKING_DAMAGE_VS_PHOENIX;
    }
    else
    {
        dmg = VIKING_DAMAGE;
    }
    if (target->abilities.getDMG(target, dmg))
    {
        return ONE;
    }
    return ZERO;
}

/* Function called in the attackShip function of the attacker that tells 
how much damage it dealt so this function can decrement the needed values; 
Returns if ship is destroyed */
int getDMGViking(Ship *ship, int dmg)
{
    ship->ships.viking.hp -= dmg;
    if (ship->ships.viking.hp < ONE)
    {
        return ONE;
    }
    return ZERO;
}

/* Function to activate the special ability of the ship */
void specialAbilityViking(Ship *ship)
{ /* Can be implemented in the future */
}

/* Prints the current status of the ship */
void printVikingStatus(Ship *ship)
{
    printf("%d health left", ship->ships.viking.hp);
}

/* Prints the ship type */
void printViking()
{
    printf("Viking");
}

/* Adding the function pointers in the Abilities structure */
Abilities createVikingAbilities(void)
{
    Abilities abilities = {&attackViking, &getDMGViking, &specialAbilityViking, &printViking};
    return abilities;
}

/* Creating the ship "object" with all its parameters */
Ship createViking(void)
{
    Abilities abilities = createVikingAbilities();
    Viking viking = {VIKING_HEALTH};
    AirShipType airShipType = VIKING;
    Ships ships;
    ships.viking = viking;
    Ship ship = {abilities, ships, &printVikingStatus, airShipType};
    return ship;
}
