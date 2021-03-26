#ifndef LIST_H_
#define LIST_H_

#include"Ship.h"

typedef struct Node{
    Ship data;
    struct Node *next;
    int index;
}Node;

typedef struct List{
    Node node;
    Node *current;
    Node *last;
}List;

List createList();
void addShip(Ship data,List *list);
Ship *getCurr(List *list);
int getCurrIndex(List *list);
void goToLast(List *list);
Ship *getLast(List *list);
Ship *getMoveCurr(List *list);
void removeShip(List *list);
int listHasCurr(List *list);

#endif /* LIST_H_ */