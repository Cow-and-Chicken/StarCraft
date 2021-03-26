#include "Battle.h"

int counter=0;

void battle(void){

    enum Victory victoryFlag;
    List terranFleet = generateTerranFleet();
    List protossFleet = generateProtossFleet();
    

    
    while(1){
        if(processTurn(&terranFleet, &protossFleet)){
            victoryFlag = TERRAN_VICTORY;
            break;
        }
        if(processTurn(&protossFleet, &terranFleet)){
            victoryFlag = PROTOSS_VICTORY;
            break;
        }

    }

    printVictory(victoryFlag);
}


int processTurn(List *attackingFleet, List *targetFleet){
    
    
    goToLast(attackingFleet);
    goToLast(targetFleet);
    Ship *target = getLast(targetFleet);
    Ship *attacker = NULL;
    
    while(listHasCurr(attackingFleet)){
        
        attacker = getCurr(attackingFleet);
        attacker->abilities.attack(attacker, target);
        if(!checkTarget(target)){
            shipDestoyed(attacker, getCurrIndex(attackingFleet), getCurrIndex(targetFleet));
            removeShip(targetFleet);
            goToLast(targetFleet);
            moveNext(targetFleet);
            target = getCurr(targetFleet);
            if(target == NULL){
                return ONE;
            }
        }
        attacker->abilities.specialAbility(attacker);
        
        moveNext(attackingFleet);
    }
    
    counter++;
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

List generateTerranFleet(void){
    char inputChar = getchar();
    List terran;
    if(inputChar=='b'){
        terran=createList(createCruser());
    }else if(inputChar=='v'){
        terran=createList(createViking());
    }
    while((inputChar=getchar())!='\n'){
        if(inputChar=='b'){
            addShip(createCruser(),&terran);
        }else if(inputChar=='v'){
            addShip(createViking(),&terran);
        }
    }

    return terran;
}

List generateProtossFleet(void){
    char inputChar = getchar();
    List protoss;
    if(inputChar=='c'){
        protoss=createList(createCarrier());
    }else if(inputChar=='p'){
        protoss=createList(createPhoenix());
    }
    while((inputChar=getchar())!='\n'){
        if(inputChar=='c'){
            addShip(createCarrier(),&protoss);
        }else if(inputChar=='p'){
            addShip(createPhoenix(),&protoss);
        }
    }
    return protoss;

}
void shipDestoyed(Ship *ship, int shipIndex, int targerIndex){
    switch(ship->type){
        case VIKING:
            printf("Viking with ID: %d killed enemy airship with ID: %d\n", shipIndex,targerIndex);
            break;
        case BATTLE_CRUSER:
            printf("BattleCruser with ID: %d killed enemy airship with ID: %d\n", shipIndex,targerIndex);
            break;
        case PHOENIX:
            printf("Phoenix with ID: %d killed enemy airship with ID: %d\n", shipIndex,targerIndex);
            break;
        case CARRIER:
            printf("Carrier with ID: %d killed enemy airship with ID: %d\n", shipIndex,targerIndex);
            break;
        default:
            printf("Something went wrong at destroy!\n");
            break;
    }
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
