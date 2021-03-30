#include "BattleCruser.h"

/* Calculating the exact amount of damage this ship is going to deal 
and passing it to the getDMG function of the ship it is attacking */
int attackCruser(Ship *attacker, List *targetFleet)
{
    int dmg = BATTLE_CRUSER_DAMAGE;
    int multiplier = DEFAULT_CRUSER_MULTIPLIER;
    if (attacker->ships.battleCruser.round % YAMATO_CANNON_LOADING_TURNS == ZERO)
    {
        multiplier = YAMATO_CANNON_MULTIPLIER;
    }
    Ship *target = getLast(targetFleet);

    if (target->abilities.getDMG(target, dmg * multiplier))
    {
        return ONE;
    }
    return ZERO;
}

/* Function called in the attackShip function of the attacker that tells 
how much damage it dealt so this function can decrement the needed values; 
Returns if ship is destroyed */
int getDMGCruser(Ship *ship, int dmg)
{
    ship->ships.battleCruser.hp -= dmg;
    if (ship->ships.battleCruser.hp < ONE)
    {
        return ONE;
    }
    return ZERO;
}

/* Function to activate the special ability of the ship */
void specialAbilityCruser(Ship *ship)
{
    ship->ships.battleCruser.round++;
}

/* Prints the current status of the ship */
void printCruserStatus(Ship *ship)
{
    printf("%d health left", ship->ships.battleCruser.hp);
}

/* Prints the ship type */
void printCruser()
{
    printf("BattleCruser");
}

/* Adding the function pointers in the Abilities structure */
Abilities createbattlecruserAbilities(void)
{
    Abilities abilities = {&attackCruser, &getDMGCruser, &specialAbilityCruser, &printCruser};
    return abilities;
}

/* Creating the ship "object" with all its parameters */
Ship createCruser(void)
{
    Abilities abilities = createbattlecruserAbilities();
    BattleCruser battlecruser = {BATTLE_CRUSER_HEALTH, BATTLE_CRUSER_START_ROUND};
    AirShipType airShipType = BATTLE_CRUSER;
    Ships ships;
    ships.battleCruser = battlecruser;
    Ship ship = {abilities, ships, &printCruserStatus, airShipType};
    return ship;
}
