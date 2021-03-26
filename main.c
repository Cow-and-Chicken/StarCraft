#include "Battle.h"

int main(){
    Ship viking = createViking();
    Ship phoenix = createPhoenix();
    viking.abilities.attack(&viking, &phoenix);
    battle();
    //printf("%d", phoenix.ships.phoenix.shield);
    return 0;
}
