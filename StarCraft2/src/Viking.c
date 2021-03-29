#include "Viking.h"

int attackViking(Ship *attacker, List *targetFleet)
{
    int dmg;
    Ship *target = getLast(targetFleet);
    if(target->type == PHOENIX){
        dmg = VIKING_DAMAGE_VS_PHOENIX;
    }
    else{
        dmg = VIKING_DAMAGE;
    }
    if(target->abilities.getDMG(target, dmg)){
        return ONE;
    }
    return ZERO;
}

int getDMGViking(Ship *ship, int dmg)
{
    ship->ships.viking.hp -= dmg;
    if(ship->ships.viking.hp < ONE){
        return ONE;
    }
    return ZERO;
}

void specialAbilityViking(Ship *ship)
{

}

Abilities createVikingAbilities(void)
{
    Abilities abilities = {&attackViking, &getDMGViking, &specialAbilityViking, &printViking};
    return abilities;
}
Ship createViking(void){
    Abilities abilities = createVikingAbilities();
    Viking Viking = {VIKING_HEALTH};
    AirShipType airShipType = VIKING;
    Ships ships;
    ships.viking = Viking;
    Ship ship = {abilities, ships, &printVikingStatus, airShipType};
    return ship;
}
void printVikingStatus(Ship *ship){
    printf("%d health left", ship->ships.viking.hp);
}
void printViking(){
    printf("Viking");
}

/* int main(void){

    Ship phoenix = createViking();
    Ship *c =&phoenix;
    c->printShipStatus(c);
    c->abilities.getDMG(c,45);
    printf("\n");
    c->printShipStatus(c);
    c->abilities.printShip(c);
    
    return 0;
} */