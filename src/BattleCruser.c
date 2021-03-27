#include "../include/BattleCruser.h"

int attackCruser(Ship *attacker,List *targetFleet){
    int dmg = BATTLE_CRUSER_DAMAGE;
    int multiplier= DEFAULT_CRUSER_MULTIPLIER;
    if(attacker->ships.battleCruser.round%YAMATO_CANNON_LOADING_TURNS==ZERO){
        multiplier=YAMATO_CANNON_MULTIPLIER;
    }
    Ship *target = getLast(targetFleet);
    
    if(target->abilities.getDMG(target,dmg*multiplier)){
        return ONE;
    }
    return ZERO;
}

int getDMGCruser(Ship *ship,int dmg){
    ship->ships.battleCruser.hp-=dmg;
    if(ship->ships.battleCruser.hp<ONE){
        return ONE;
    }
    return ZERO;
}

void specialAbilityCruser(Ship *ship){
   ship->ships.battleCruser.round++;
}

void printCruserStatus(Ship *ship){
    printf("%d health left",ship->ships.battleCruser.hp);
}

void printCruser(Ship *ship){
    printf("BattleCruser");
}

Abilities createbattlecruserAbilities(void){
    Abilities abilities = {&attackCruser, &getDMGCruser, &specialAbilityCruser,&printCruser};
    return abilities;
}



Ship createCruser(void){
    Abilities abilities = createbattlecruserAbilities();
    BattleCruser battlecruser = {BATTLE_CRUSER_HEALTH,BATTLE_CRUSER_START_ROUND};
    AirShipType airShipType = BATTLE_CRUSER;
    Ships ships;
    ships.battleCruser = battlecruser;
    Ship ship = {abilities, ships,&printCruserStatus, airShipType};
    return ship;
}
/* int main(void){

    Ship phoenix = createCruser();
    Ship *c =&phoenix;
    c->printShipStatus(c);
    c->abilities.getDMG(c,45);
    printf("\n");
    c->printShipStatus(c);
    c->abilities.printShip(c);
    
    return 0;
} */