#include "Ship.h"

void attackCarrier(Ship *attacker,Ship *attacked){
    droneCheckCarrier(attacker);
    int dmg=attacker->ships.carrier.drones*CARRIER_DAMAGE;
    attacked->abilities.getDMG(attacked,dmg);
}

void getDMGCarrier(Ship *ship,int dmg){
    if(ship->ships.carrier.shield>dmg){
        ship->ships.carrier.shield-=dmg;
        dmg=ZERO;
    }else{
        dmg-=ship->ships.carrier.shield;
        ship->ships.carrier.shield=ZERO;
    }
    ship->ships.carrier.hp-=dmg;
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

Abilities createCarrierAbilities(void){
    Abilities abilities={&attackCarrier,&getDMGCarrier,&specialAbilityCarrier};
    return abilities;
}

Ship createCarrier(void){
    Abilities abilities=createCarrierAbilities();
    Carrier carrier={CARRIER_HEALTH,CARRIER_SHIELD,MAX_INTERCEPTORS};
    AirShipType airShipType = CARRIER;
    Ship ship={abilities,carrier,airShipType};
    return ship;
}