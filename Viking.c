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
    Ship battlecruser=createCruser();
    Ship *v = &viking;
    Ship *c = &carrier;
    Ship *p = &phoenix;
    Ship *b = &battlecruser;
    /* printf("Carier`s shield: %d\n", carrier.ships.carrier.shield);
    printf("Phoenix`s shield: %d\n", phoenix.ships.phoenix.shield);
    printf("\n\n");
    viking.abilities.attack(v, c);
    viking.abilities.attack(v, p);
    printf("Carier`s shield: %d\n", carrier.ships.carrier.shield);
    printf("Phoenix`s shield: %d\n", phoenix.ships.phoenix.shield); */
    /*round 1  */
    battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    /* round 2 */
     battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    /* round 3 */
     battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    /* round4 */
     battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    /* round 5 */
     battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    /* round 6 */
     battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);

    /* round 7 */
    battlecruser.abilities.attack(b,c);
    printf("Carrier's shield: %d\n",carrier.ships.carrier.shield);
    printf("Carrier's hp: %d\n",carrier.ships.carrier.hp);
    printf("\n");
    printf("\n");
    battlecruser.abilities.specialAbility(b);
    carrier.abilities.specialAbility(c);
    return 0;


}