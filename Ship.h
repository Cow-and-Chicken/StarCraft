#include "Abilities.h"
#include "Carrier.h"
#include "Defines.h"
#include "Phoenix.h"

union Ships{
    Carrier carrier;
    Phoenix phoenix;
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