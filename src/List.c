#include "List.h"

/* Function that creates a List, we'll use to create a ProtosFleet List and a TerranFleet List */
List createList()
{
    Node *new = malloc(sizeof(Node));
    new->itemIndex = MINUS_ONE;
    new->nextItem = NULL;
    new->prevItem = NULL;
    List list = {*new, new, new, new};
    return list;
}

/* Adds a ship to the list */
void addShip(Ship data, List *list)
{
    Node *new = malloc(sizeof(Node));
    new->itemIndex = list->lastItem->itemIndex + ONE;
    new->prevItem = list->lastItem;
    new->nextItem = NULL;

    new->shipData.abilities = data.abilities;
    new->shipData.printShipStatus = data.printShipStatus;
    new->shipData.ships = data.ships;
    new->shipData.type = data.type;

    list->lastItem->nextItem = new;

    list->lastItem = new;
}

/* Returns the current ship */
Ship *getCurrShip(List *list)
{
    return &list->currentItem->shipData;
}

/* Returns the current ship index */
int getCurrIndex(List *list)
{
    return list->currentItem->itemIndex;
}

/* Returns the index of the last ship in the List */
int getLastIndex(List *list)
{
    return list->lastItem->itemIndex;
}

/* Sets the current item to be the last */
void goToLast(List *list)
{
    list->currentItem = list->lastItem;
}

/* Sets the current item to be the first that is NULL */
void goToFirst(List *list)
{
    list->currentItem = list->firstItem;
}

/* Returns the last ship */
Ship *getLast(List *list)
{
    return &list->lastItem->shipData;
}

/* Returns the first ship that is NULL*/
Ship *getFirst(List *list)
{
    return &list->firstItem->shipData;
}

/* Removes and frees the last item */
void removeLastShip(List *list)
{
    Node *tempNode = list->lastItem;
    list->lastItem = list->lastItem->prevItem;
    list->lastItem->nextItem = NULL;
    list->currentItem = list->lastItem;
    free(tempNode);
}

/* Sets the current item to the next one */
void moveToNext(List *list)
{
    if (list->currentItem->nextItem != NULL)
    {
        list->currentItem = list->currentItem->nextItem;
    }
}

/* Sets the current item to the previous one */
void moveToPrev(List *list)
{
    if (list->currentItem->itemIndex > MINUS_ONE)
    {
        list->currentItem = list->currentItem->prevItem;
    }
}

/* Checks if list is empty */
int listIsEmpty(List *list)
{
    if (getLastIndex(list) == MINUS_ONE)
    {
        return ONE;
    }
    return ZERO;
}
