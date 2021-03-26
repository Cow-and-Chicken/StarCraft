#include "Battle.h"

void battle(void){

    enum Victory victoryFlag;
    List *protossFleet = generateProtossFleet();
    List *terranFleet = generateTerranFleet();
    goToLast(terranFleet);
    while(1){
        if(processTurn(terranFleet, protossFleet)){
            victoryFlag = TERRAN_VICTORY;
            break;
        }
        if(processTurn(protossFleet, terranFleet)){
            victoryFlag = PROTOSS_VICTORY;
            break;
        }

    }
}


int processTurn(List *attackingFleet, List *targetFleet){
    goToLast(attackingFleet);
    Ship *target = getLast(targetFleet);
    Ship *attacker = NULL;
    
    while(listHasCurr(attackingFleet)){
        attacker = getMoveCurr(attackingFleet);
        
        attacker->abilities.attack(attacker, target);
        printf("Start\n");
        
        if(!checkTarget(target)){
            shipDestoyed(attacker, getCurrIndex(attackingFleet), getCurrIndex(targetFleet));
            removeShip(targetFleet);
            target = getLast(targetFleet);
            if(target == NULL){
                return ONE;
            }
        }
        attacker->abilities.specialAbility(attacker);
        printf("Start\n");
    }
   
    printShip(target, getCurrIndex(targetFleet));
    return ZERO;
}


void printShip(Ship *ship, int shipIndex){
    if(ship->type < CARRIER){
        printTerranShip(ship, shipIndex);
    }
    else
    {
        printProtossShip(ship, shipIndex);
    }
}


void printVictory(enum Victory victoryFlag){
    switch (victoryFlag)
    {
    case PROTOSS_VICTORY:
        printf("PROTOSS has won!\n");
        break;
    case TERRAN_VICTORY:
        printf("TERRAN has won!\n");
        break;
    default:    
        printf("Something went wrong!\n");
        break;
    }
}


int checkTarget(Ship *ship){
    switch (ship->type)
    {
    case VIKING:
        if(ship->ships.viking.hp < ONE){
            return ZERO;
        }
        break;
    case BATTLE_CRUSER:
        if(ship->ships.battleCruser.hp < ONE){
            return ZERO;
        }
        break;
    case PHOENIX:
        if(ship->ships.phoenix.hp < ONE){
            return ZERO;
        }
        break;
    case CARRIER:
        if(ship->ships.carrier.hp < ONE){
            return ZERO;
        }
        break;
    
    default:
        printf("Ship check went wrong!\n");
        break;
    }
    return ONE;
}

List *generateTerranFleet(void){
    List terran = createList(createCruser());
    List *terranFleet = &terran;
    return terranFleet;
}

List *generateProtossFleet(void){
    List protoss = createList(createCarrier());
    List *protossFleet = &protoss;
    return protossFleet;

}
void shipDestoyed(Ship *ship, int shipIndex, int targerIndex){
    printf("1\n");
}
void printTerranShip(Ship *ship, int shipIndex){
    switch(ship->type){
        case VIKING:
            printf("Last Terran AirShip with ID: %d has %d health left\n", shipIndex, ship->ships.viking.hp);
            break;
        case BATTLE_CRUSER:
            printf("Last Terran AirShip with ID: %d has %d health left\n", shipIndex, ship->ships.battleCruser.hp);
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
}
void printProtossShip(Ship *ship, int shipIndex){
    switch(ship->type){
        case PHOENIX:
            printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", shipIndex, ship->ships.phoenix.hp, ship->ships.phoenix.shield);
            break;
        case CARRIER:
            printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", shipIndex, ship->ships.carrier.hp, ship->ships.carrier.shield);
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
}
