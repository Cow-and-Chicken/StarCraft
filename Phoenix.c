#include "Ship.h"

void attackPhoenix(Ship *attacker,Ship *attacked){
    int dmg = PHOENIX_DAMAGE;
    attacked->abilities.getDMG(attacked, dmg);
}

void getDMGPhoenix(Ship *ship,int dmg){
    if(ship->ships.phoenix.shield>dmg){
        ship->ships.phoenix.shield-=dmg;
        dmg=ZERO;
    }else{
        dmg-=ship->ships.phoenix.shield;
        ship->ships.phoenix.shield=ZERO;
    }
    ship->ships.phoenix.hp-=dmg;
}

void specialAbilityPhoenix(Ship *ship){
    ship->ships.phoenix.shield+=PHOENIX_SHIELD_REGENERATE_RATE;
    if(ship->ships.phoenix.shield>PHOENIX_SHIELD){
        ship->ships.phoenix.shield=PHOENIX_SHIELD;
    }
}

Abilities createPhoenixAbilities(void){
    Abilities abilities = {&attackPhoenix, &getDMGPhoenix, &specialAbilityPhoenix};
    return abilities;
}

Ship createPhoenix(void){
    Abilities abilities = createPhoenixAbilities();
    Phoenix phoenix = {PHOENIX_HEALTH, PHOENIX_SHIELD};
    AirShipType airShipType = PHOENIX;
    Ship ship = {abilities, phoenix, airShipType};
    return ship;
}