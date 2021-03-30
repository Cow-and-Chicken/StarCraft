#include "Carrier.h"

/* Calculating the exact amount of damage this ship is going to deal 
and passing it to the getDMG function of the ship it is attacking */
int attackCarrier(Ship *attacker, List *targetFleet)
{
    droneCheckCarrier(attacker);
    int dmg = CARRIER_DAMAGE;
    int drones, exitStatus = ZERO;
    Ship *target = getLast(targetFleet);

    for (drones = 0; drones < attacker->ships.carrier.drones; drones++)
    {
        if (target->abilities.getDMG(target, dmg))
        {
            exitStatus = ONE;
            goToLast(targetFleet);
            if (getCurrIndex(targetFleet) != ZERO)
            {
                moveToPrev(targetFleet);
                target = getCurrShip(targetFleet);
            }
            else
            {
                return exitStatus;
            }
        }
    }

    return exitStatus;
}

/* Function called in the attackShip function of the attacker that tells 
how much damage it dealt so this function can decrement the needed values; 
Returns if ship is destroyed */
int getDMGCarrier(Ship *ship, int dmg)
{
    if(ship->ships.carrier.shield > dmg)
    {
        ship->ships.carrier.shield -= dmg;
        dmg = ZERO;
    }
    else
    {
        dmg -= ship->ships.carrier.shield;
        ship->ships.carrier.shield = ZERO;
    }
    ship->ships.carrier.hp -= dmg;

    if(ship->ships.carrier.hp < ONE)
    {
        return ONE;
    }
    return ZERO;
}

/* Checks the carrier status and how many drones it should has */
void droneCheckCarrier(Ship *ship)
{
    if (ship->ships.carrier.hp < CARRIER_HEALTH)
    {
        ship->ships.carrier.drones = DAMAGED_STATUS_INTERCEPTORS;
    }
}

/* Function to activate the special ability of the ship */
void specialAbilityCarrier(Ship *ship)
{
    ship->ships.carrier.shield += CARRIER_SHIELD_REGENERATE_RATE;
    if (ship->ships.carrier.shield > CARRIER_SHIELD)
    {
        ship->ships.carrier.shield = CARRIER_SHIELD;
    }
}

/* Prints the current status of the ship */
void printCarrierStatus(Ship *ship)
{
    printf("%d health and %d shield left", ship->ships.carrier.hp, ship->ships.carrier.shield);
}

/* Prints the ship type */
void printCarrier()
{
    printf("Carrier");
}

/* Adding the function pointers in the Abilities structure */
Abilities createCarrierAbilities(void)
{
    Abilities abilities = {&attackCarrier, &getDMGCarrier, &specialAbilityCarrier, &printCarrier};
    return abilities;
}

/* Creating the ship "object" with all its parameters */
Ship createCarrier(void)
{
    Abilities abilities = createCarrierAbilities();
    Carrier carrier = {CARRIER_HEALTH, CARRIER_SHIELD, MAX_INTERCEPTORS};
    AirShipType airShipType = CARRIER;
    Ships ships;
    ships.carrier = carrier;
    Ship ship = {abilities, ships, &printCarrierStatus, airShipType};
    return ship;
}
