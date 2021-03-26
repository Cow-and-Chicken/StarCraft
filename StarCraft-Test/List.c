#include "List.h"

/* Function that creates a List, we'll use to create a ProtosFleet List and a TerranFleet List */
List createList(Ship data){
    Node *curr = malloc(sizeof(Node));
    curr->data.abilities = data.abilities;
    curr->data.ships = data.ships;
    curr->data.type = data.type;
    curr->next=NULL;
    Node *last = curr;
    List list = {*curr,curr,last};
    return list;
}

/* Adding a ship to the specific list */
void addShip(Ship data, List *list){
    Node *p=malloc(sizeof(Node));
    p->data.abilities=data.abilities;
    p->data.ships=data.ships;
    p->data.type=data.type;
    p->next=list->last;
    list->last=p;
    
}

/* Getting the ship we are currently on */
Ship *getCurr(List *list){
    return &list->current->data;
}

/* Setting the current ship we are on to be the last one */
void goToLast(List *list){
    list->current=list->last;
}

/* Getting the last ship of the list */
Ship *getLast(List *list){
    return &list->last->data;
}

/* Getting the ship we are currently on and then moving the current ship to the one it's pointing to */
Ship *getMoveCurr(List *list){

    if(listHasCurr(list)){
        Ship *ptr=&list->current->data;
        list->current=list->current->next;
        return ptr;
    }else{
        return NULL;
    }
}

/* Removing the last ship , and setting the next one to be the new last */
void removeShip(List *list){
    if(list->last->next){
        Node *ptr=list->last;
        list->last=list->last->next;
        free(ptr);
    }    
}


/*Checks if Curr is an item*/
int listHasCurr(List *list){
    if(list->current!=NULL){
        return ONE;
    }
    return ZERO;
}

int main(){

    List terranList=createList(createCruser());
    List *terranFleet=&terranList;
    Ship *attacker;
    Ship *target;
    for(int i=0;i<5;i++){
        addShip(createViking(),terranFleet);
    }
    goToLast(terranFleet);
    attacker=getMoveCurr(terranFleet);
    target=getCurr(terranFleet);

    goToLast(terranFleet);
    while(listHasCurr(terranFleet)){
        Ship *p=getMoveCurr(terranFleet);
        printf("Ship type %d hp: %d\n",p->type,p->ships.viking.hp);
    }

    goToLast(terranFleet);
    printf("\n\n");
    attacker->abilities.attack(attacker,target);
    goToLast(terranFleet);
    while(listHasCurr(terranFleet)){
        Ship *p=getMoveCurr(terranFleet);
        printf("Ship type %d hp: %d\n",p->type,p->ships.viking.hp);
    }
    goToLast(terranFleet);
    printf("\n\n");
    goToLast(terranFleet);
    while(listHasCurr(terranFleet)){
        Ship *p=getMoveCurr(terranFleet);
        printf("Ship type %d hp: %d\n",p->type,p->ships.viking.hp);
    }

    goToLast(terranFleet);
    return 0;
}


 