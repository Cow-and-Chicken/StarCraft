#include "Abilities.h"
#include "Carrier.h"
#include "Defines.h"
#include "Phoenix.h"
#include "Viking.h"
#include "BattleCruser.h"


union Ships{
    Carrier carrier;
    Phoenix phoenix;
    Viking viking;
    BattleCruser battleCruser;
};

struct Ship{
    /*Ship abilities*/
    Abilities abilities;
    /*Ship stats: hp, shield...*/
    Ships ships;
    /*Type of ship*/
    AirShipType type;
};

Ship createCruser(void);
Ship createViking(void);
Ship createPhoenix(void);
Ship createCarrier(void);
