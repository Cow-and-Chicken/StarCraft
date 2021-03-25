#include"Ship.h"
typedef struct Node{
    Ship data;
    struct Node *next;

}Node;
typedef struct List{
    Node node;
    Node *current;
    Node *last;
}List;

List createList(Ship data);
void addShip(Ship data,List *list);
Ship *getCurr(void);
void goToLast(void);
Ship *getLast(void);
Ship *getMoveCurr(void);
void removeShip(Ship *ptr);