#include "Battle.h"


/* The main battle function that handles the battle and its result */
void battle(void)
{

    enum Victory victoryFlag;
    List terran = createList();
    List protoss = createList();
    List *terranFleet = &terran;
    List *protossFleet = &protoss;
    generateTerranFleet(terranFleet);
    generateProtossFleet(protossFleet);

    while (1)
    {
        if (processTurn(terranFleet, protossFleet))
        {
            victoryFlag = TERRAN_VICTORY;
            break;
        }
        printf("Last Protoss AirShip");
        goToLast(protossFleet);
        printShip(getLast(protossFleet), getCurrIndex(protossFleet));

        if (processTurn(protossFleet, terranFleet))
        {
            victoryFlag = PROTOSS_VICTORY;
            break;
        }
        printf("Last Terran AirShip");
        goToLast(terranFleet);
        printShip(getLast(terranFleet), getCurrIndex(terranFleet));
    }

    printVictory(victoryFlag);
}

/* Handles the actual turns of the battle */
int processTurn(List *attackingFleet, List *targetFleet)
{
    goToLast(targetFleet);
    goToFirst(attackingFleet);
    moveToNext(attackingFleet);
    Ship *attacker;
    attacker = getCurrShip(attackingFleet);

    while (1)
    {
        attacker = getCurrShip(attackingFleet);
        if (attacker->abilities.attack(attacker, targetFleet))
        {
            goToLast(targetFleet);
            shipDestoyed(attacker, getCurrIndex(attackingFleet), getCurrIndex(targetFleet));
            removeLastShip(targetFleet);
            if (listIsEmpty(targetFleet))
            {
                return ONE;
            }
        }
        attacker->abilities.specialAbility(attacker);
        if (getCurrIndex(attackingFleet) == getLastIndex(attackingFleet))
        {
            break;
        }
        moveToNext(attackingFleet);
    }
    return ZERO;
}

/* Prints the ship ID and its status */
void printShip(Ship *ship, int shipIndex)
{

    printf(" with ID: %d has ", shipIndex);
    ship->printShipStatus(ship);
    printf("\n");
}

/* Prints the final result of the battle */
void printVictory(enum Victory victoryFlag)
{
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

/* Fills the terran fleet List */
void generateTerranFleet(List *terranFleet)
{
    char inputChar;

    while ((inputChar = getchar()) != '\n')
    {
        if (inputChar == 'b')
        {
            addShip(createCruser(), terranFleet);
        }
        else if (inputChar == 'v')
        {
            addShip(createViking(), terranFleet);
        }
    }
}

/* Fills the protoss fleet List */
void generateProtossFleet(List *protossFleet)
{
    char inputChar;

    while ((inputChar = getchar()) != '\n')
    {
        if (inputChar == 'c')
        {
            addShip(createCarrier(), protossFleet);
        }
        else if (inputChar == 'p')
        {
            addShip(createPhoenix(), protossFleet);
        }
    }
}

/* Prints the destroyer ship with its ID and the target ID */
void shipDestoyed(Ship *ship, int shipIndex, int targetIndex)
{
    ship->abilities.printShip();
    printf(" with ID: %d killed enemy airship with ID: %d\n", shipIndex, targetIndex);
}
