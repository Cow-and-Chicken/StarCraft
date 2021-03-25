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
Ship *getCurr(List *list){
     return &list->current->data;
}
void goToLast(List *list){
    list->current=list->last;
}
Ship *getLast(List *list){
    return &list->last->data;
}
Ship *getMoveCurr(List *list){
    Ship *ptr=&list->current->data;
    if(list->current->next){
        list->current=list->current->next;
    }else{
        list->current=list->last;
    }
    return ptr;
}
void removeShip(List *list){
    Node *ptr=list->last;
    list->last=list->last->next;
    free(ptr);
}
int main(){
    Ship viking = createViking();
    Ship carrier = createCarrier();
    Ship phoenix = createPhoenix();
    Ship battlecruser=createCruser();
    Ship *v = NULL;
    Ship *c = NULL;
    Ship *p = &phoenix;
    Ship *b = &battlecruser;
    List protosFleet=createList(viking);
    addShip(carrier,&protosFleet);
    goToLast(&protosFleet);
    c=getMoveCurr(&protosFleet);
    v=getMoveCurr(&protosFleet);
    printf("\n");
    printf("%d\n",c->ships.carrier.hp);
    printf("\n");
    printf("%d\n",v->ships.viking.hp);
    return 0;
 

}


 