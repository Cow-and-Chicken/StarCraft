#include "Ship.h"

void attackCruser(Ship *attacker,Ship *attacked){
    int dmg = BATTLE_CRUSER_DAMAGE;
    int multiplier= DEFAULT_CRUSER_MULTIPLIER;
    if(attacker->ships.battleCruser.round%YAMATO_CANNON_LOADING_TURNS==ZERO){
        multiplier=YAMATO_CANNON_MULTIPLIER;
    }
    attacked->abilities.getDMG(attacked, dmg*multiplier);
}

void getDMGCruser(Ship *ship,int dmg){
    
    ship->ships.battleCruser.hp-=dmg;
}

void specialAbilityCruser(Ship *ship){
   ship->ships.battleCruser.round++;
}

Abilities createbattlecruserAbilities(void){
    Abilities abilities = {&attackCruser, &getDMGCruser, &specialAbilityCruser};
    return abilities;
}

Ship createCruser(void){
    Abilities abilities = createbattlecruserAbilities();
    BattleCruser battlecruser = {BATTLE_CRUSER_HEALTH,BATTLE_CRUSER_START_ROUND};
    AirShipType airShipType = BATTLE_CRUSER;
    Ships ships;
    ships.battleCruser = battlecruser;
    Ship ship = {abilities, ships, airShipType};
    return ship;
}