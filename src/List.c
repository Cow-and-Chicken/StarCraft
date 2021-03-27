#include "../include/List.h"

/* Function that creates a List, we'll use to create a ProtosFleet List and a TerranFleet List */
List createList(){
    Node *new = malloc(sizeof(Node));
    new->itemIndex = MINUS_ONE;
    new->nextItem=NULL;
    new->prevItem=NULL;
    List list = {*new,new,new,new};
    return list;
}

/*Add a ship to the list*/
void addShip(Ship data,List *list){
    Node *new = malloc(sizeof(Node));
    new->itemIndex=list->lastItem->itemIndex+ONE;
    new->prevItem=list->lastItem;
    new->nextItem=NULL;

    new->shipData.abilities=data.abilities;
    new->shipData.printShipStatus=data.printShipStatus;
    new->shipData.ships=data.ships;
    new->shipData.type=data.type;

    list->lastItem->nextItem=new;

    list->lastItem=new;
}


Ship *getCurrShip(List *list){
    return &list->currentItem->shipData;
}


int getCurrIndex(List *list){
    return list->currentItem->itemIndex;
}
int getLastIndex(List *list){
    return list->lastItem->itemIndex;
}


void goToLast(List *list){
    list->currentItem=list->lastItem;
}


void goToFirst(List *list){
    list->currentItem=list->firstItem;
}


Ship *getLast(List *list){
    return &list->lastItem->shipData;
}


Ship *getFirst(List *list){
    return &list->firstItem->shipData;
}


void removeLastShip(List *list){
    list->lastItem=list->lastItem->prevItem;
    list->lastItem->nextItem=NULL;
    list->currentItem=list->lastItem;
}


int listHasNext(List *list){
    if(list->currentItem->nextItem!=NULL){
        return ONE;
    }
    return ZERO;
}   

int listHasPrev(List *list){
    if(list->currentItem->itemIndex>MINUS_ONE){
        return ONE;
    }
    return ZERO;
}

void moveToNext(List *list){
    if(list->currentItem->nextItem!=NULL){
        list->currentItem=list->currentItem->nextItem;
    }
}


void moveToPrev(List *list){
    if(list->currentItem->itemIndex>MINUS_ONE){
        list->currentItem=list->currentItem->prevItem;
    }   
}

int listIsEmpty(List *list){
    if(getLastIndex(list)==MINUS_ONE){
        return ONE;
    }
    return ZERO;
}

 