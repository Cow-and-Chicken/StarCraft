#include "Ship.h"

void attackViking(Ship *attacker, Ship *attacked)
{
    int dmg;
    if(attacked->type == PHOENIX){
        dmg = VIKING_DAMAGE_VS_PHOENIX;
    }
    else{
        dmg = VIKING_DAMAGE;
    }
    attacked->abilities.getDMG(attacked,dmg);
}

void getDMGViking(Ship *ship, int dmg)
{
    ship->ships.viking.hp -= dmg;
}

void specialAbilityViking(Ship *ship)
{

}

Abilities createVikingAbilities(void)
{
    Abilities abilities = {&attackViking, &getDMGViking, &specialAbilityViking};
    return abilities;
}
Ship createViking(void){
    Abilities abilities = createVikingAbilities();
    Viking Viking = {VIKING_HEALTH};
    AirShipType airShipType = VIKING;
    Ships ships;
    ships.viking = Viking;
    Ship ship = {abilities, ships, airShipType};
    return ship;
}

    