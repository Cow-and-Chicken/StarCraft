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
int main(){
    Ship viking = createViking();
    Ship carrier = createCarrier();
    Ship phoenix = createPhoenix();

    Ship *v = &viking;
    Ship *c = &carrier;
    Ship *p = &phoenix;

    printf("Carier`s shield: %d\n", carrier.ships.carrier.shield);
    printf("Phoenix`s shield: %d\n", phoenix.ships.phoenix.shield);
    printf("\n\n");
    viking.abilities.attack(v, c);
    viking.abilities.attack(v, p);
    printf("Carier`s shield: %d\n", carrier.ships.carrier.shield);
    printf("Phoenix`s shield: %d\n", phoenix.ships.phoenix.shield);

    return 0;


}