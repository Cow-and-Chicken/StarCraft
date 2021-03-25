#include "List.h"

List createList(Ship data){
    Node *curr = malloc(sizeof(Node));
    curr->data.abilities = data.abilities;
    curr->data.ships = data.ships;
    curr->data.type = data.type;
    Node *last = curr;
    List list = {*curr,curr,last};
    return list;
}
void addShip(Ship data, List *list){
    Node *p=malloc(sizeof(Node));
    p->data.abilities=data.abilities;
    p->data.ships=data.ships;
    p->data.type=data.type;
    p->next=list->last;
    list->last=p;
    
}
Ship *getCurr(void);
void goToLast(void);
Ship *getLast(void);
Ship *getMoveCurr(void);
void removeShip(Ship *ptr);
int main()
{
    return 0;
}
