#include "Carrier.h"

int attackCarrier(Ship *attacker,List *targetFleet){
    droneCheckCarrier(attacker);
    int dmg = CARRIER_DAMAGE;
    int drones, exitStatus=ZERO;
    Ship *target = getLast(targetFleet);

    for(drones=0;drones<attacker->ships.carrier.drones;drones++){
        if(target->abilities.getDMG(target,dmg)){
            exitStatus=ONE;
            goToLast(targetFleet);
            if(listHasPrev(targetFleet)){
                moveToPrev(targetFleet);
                target=getCurrShip(targetFleet);
            }else{
                return exitStatus;
            }
        }
    }

    return exitStatus;
}

int getDMGCarrier(Ship *ship,int dmg){
    if(ship->ships.carrier.shield>dmg){
        ship->ships.carrier.shield-=dmg;
        dmg=ZERO;
    }else{
        dmg-=ship->ships.carrier.shield;
        ship->ships.carrier.shield=ZERO;
    }
    ship->ships.carrier.hp-=dmg;

    if(ship->ships.carrier.hp<ONE){
        return ONE;
    }
    return ZERO;
}

void droneCheckCarrier(Ship *ship){
    if(ship->ships.carrier.hp<CARRIER_HEALTH){
        ship->ships.carrier.drones=DAMAGED_STATUS_INTERCEPTORS;
    }
}

void specialAbilityCarrier(Ship *ship){
    ship->ships.carrier.shield+=CARRIER_SHIELD_REGENERATE_RATE;
    if(ship->ships.carrier.shield>CARRIER_SHIELD){
        ship->ships.carrier.shield=CARRIER_SHIELD;
    }
}

void printCarrierStatus(Ship *ship){
    printf("%d health and %d shield left",ship->ships.carrier.hp,ship->ships.carrier.shield);

}
void printCarrier(Ship *ship){
    printf("Carrier");
}

Abilities createCarrierAbilities(void){
    Abilities abilities={&attackCarrier,&getDMGCarrier,&specialAbilityCarrier,&printCarrier};
    return abilities;
}

Ship createCarrier(void){
    Abilities abilities=createCarrierAbilities();
    Carrier carrier={CARRIER_HEALTH,CARRIER_SHIELD,MAX_INTERCEPTORS};
    AirShipType airShipType = CARRIER;
    Ships ships;
    ships.carrier = carrier;
    Ship ship = {abilities, ships,&printCarrierStatus, airShipType};
    return ship;
}


int main(void){

    Ship carrier = createCarrier();
    Ship *c =&carrier;
    c->printShipStatus(c);
    c->abilities.getDMG(c,180);
    printf("\n");
    c->printShipStatus(c);

    printf("\n\n\n");
    List protossFleet=createList();
    List *p =&protossFleet;
    addShip(createCarrier(),p);
    addShip(createCarrier(),p);

    goToLast(p);

    Ship *target=getCurrShip(p);
    printf("Index: %d\n",getCurrIndex(p));
    c->printShipStatus(target);
    printf("\n");
    moveToPrev(p);
    Ship *attacker= getCurrShip(p);
    printf("Index: %d\n",getCurrIndex(p));
    c->printShipStatus(attacker);
    printf("\n\n\n\n");
    attacker->abilities.attack(attacker,p);
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    attacker->abilities.attack(attacker,p);
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    attacker->abilities.attack(attacker,p);
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    attacker->abilities.attack(attacker,p);
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    if(attacker->abilities.attack(attacker,p)){
        printf("Target destroyed\n");
    }
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    if(attacker->abilities.attack(attacker,p)){
        printf("Target destroyed\n");
        attacker->abilities.printShip(attacker);
        printf(" with id %d killed enemy airship with ID:\n",getCurrIndex(p));
    }
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    if(attacker->abilities.attack(attacker,p)){
        printf("Target destroyed\n");
        attacker->abilities.printShip(attacker);
        printf(" with id %d killed enemy airship with ID:\n",getCurrIndex(p));
        moveToPrev(p);
        target=getCurrIndex;
        removeLastShip(p);
    }
    c->printShipStatus(target);
    printf("\n");
    c->printShipStatus(attacker);
    printf("\n\n");

    return 0;
}