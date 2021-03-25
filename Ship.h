#include "Abilities.h"
#include "Carrier.h"
#include "Defines.h"
#include "Phoenix.h"
#include "Viking.h"


union Ships{
    Carrier carrier;
    Phoenix phoenix;
    Viking viking;
};

struct Ship{
    /*Ship abilities*/
    Abilities abilities;
    /*Ship stats: hp, shield...*/
    Ships ships;
    /*Type of ship*/
    AirShipType type;
};

Ship createCruiser(void);
Ship createViking(void);
Ship createPhoenix(void);
Ship createCarrier(void);