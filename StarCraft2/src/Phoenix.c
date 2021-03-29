#include "Phoenix.h"

/* Calculating the exact amount of damage this ship is going to deal 
and passing it to the getDMG function of the ship it is attacking */
int attackPhoenix(Ship *attacker, List *targetFleet){
    int dmg = PHOENIX_DAMAGE;
    Ship *target = getLast(targetFleet);
    if(target->abilities.getDMG(target, dmg)){
        return ONE;
    }
    return ZERO;
}

/* Function called in the attackShipName function of the attacker that tells 
how much damage it dealt so this function can decrement the needed values */
int getDMGPhoenix(Ship *ship, int dmg){
    if(ship->ships.phoenix.shield>dmg){
        ship->ships.phoenix.shield-=dmg;
        dmg=ZERO;
    }else{
        dmg-=ship->ships.phoenix.shield;
        ship->ships.phoenix.shield=ZERO;
    }
    ship->ships.phoenix.hp-=dmg;
    if(ship->ships.phoenix.hp < ONE){
        return ONE;
    }
    return ZERO;
}

/* Function to activate the special ability of the ship */
void specialAbilityPhoenix(Ship *ship){
    ship->ships.phoenix.shield+=PHOENIX_SHIELD_REGENERATE_RATE;
    if(ship->ships.phoenix.shield>PHOENIX_SHIELD){
        ship->ships.phoenix.shield=PHOENIX_SHIELD;
    }
}

void printPhoenixStatus(Ship *ship){
    printf("%d health and %d shield left", ship->ships.phoenix.hp, ship->ships.phoenix.shield);
}

void printPhoenix(){
    printf("Phoenix");
}

/* Adding the function pointers in the Abilities structure */
Abilities createPhoenixAbilities(void){
    Abilities abilities = {&attackPhoenix, &getDMGPhoenix, &specialAbilityPhoenix, &printPhoenix};
    return abilities;
}

/* Creating the ship "object" with all its parameters */
Ship createPhoenix(void){
    Abilities abilities = createPhoenixAbilities();
    Phoenix phoenix = {PHOENIX_HEALTH, PHOENIX_SHIELD};
    AirShipType airShipType = PHOENIX;
    Ships ships;
    ships.phoenix = phoenix;
    Ship ship = {abilities, ships, &printPhoenixStatus, airShipType};
    return ship;
}

/* int main(void){

    Ship phoenix = createPhoenix();
    Ship *c =&phoenix;
    c->printShipStatus(c);
    c->abilities.getDMG(c,45);
    printf("\n");
    c->printShipStatus(c);
    c->abilities.printShip(c);
    
    return 0;
} */