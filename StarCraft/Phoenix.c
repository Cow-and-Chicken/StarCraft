#include "Ship.h"

/* Calculating the exact amount of damage this ship is going to deal 
and passing it to the getDMG function of the ship it is attacking */
void attackPhoenix(Ship *attacker,Ship *attacked){
    int dmg = PHOENIX_DAMAGE;
    attacked->abilities.getDMG(attacked, dmg);
}

/* Function called in the attackShipName function of the attacker that tells 
how much damage it dealed so this function can decrement the needed variables */
void getDMGPhoenix(Ship *ship, int dmg){
    if(ship->ships.phoenix.shield>dmg){
        ship->ships.phoenix.shield-=dmg;
        dmg=ZERO;
    }else{
        dmg-=ship->ships.phoenix.shield;
        ship->ships.phoenix.shield=ZERO;
    }
    ship->ships.phoenix.hp-=dmg;
}

/* Function to activate the special ability of the ship */
void specialAbilityPhoenix(Ship *ship){
    ship->ships.phoenix.shield+=PHOENIX_SHIELD_REGENERATE_RATE;
    if(ship->ships.phoenix.shield>PHOENIX_SHIELD){
        ship->ships.phoenix.shield=PHOENIX_SHIELD;
    }
}

/* Creating the function pointers in the Abilities structure */
Abilities createPhoenixAbilities(void){
    Abilities abilities = {&attackPhoenix, &getDMGPhoenix, &specialAbilityPhoenix};
    return abilities;
}

/* Creating the ship "object" with all its parameters */
Ship createPhoenix(void){
    Abilities abilities = createPhoenixAbilities();
    Phoenix phoenix = {PHOENIX_HEALTH, PHOENIX_SHIELD};
    AirShipType airShipType = PHOENIX;
    Ships ships;
    ships.phoenix = phoenix;
    Ship ship = {abilities, ships, airShipType};
    return ship;
}
