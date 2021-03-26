#ifndef LIST_H_
#define LIST_H_

#include "Ship.h"

typedef struct Node{
    Ship shipData;
    Node *nextItem;
    Node *prevItem;
    int itemIndex;
}Node;

typedef struct List{
    Node node;
    Node *currentItem;
    Node *lastItem;
    Node *firstItem;
}List;

List createList(void);
void addShip(Ship data,List *list);
Ship *getCurrShip(List *list);
int getCurrIndex(List *list);
int getLastIndex(List *list);
void goToLast(List *list);
void goToFirst(List *list);
Ship *getLast(List *list);
Ship *getFirst(List *list);
void removeLastShip(List *list);
int listHasNext(List *list);
int listHasPrev(List *list);
void moveToNext(List *list);
void moveToPrev(List *list);
int listIsEmpty(List *list);

#endif /* LIST_H_ */