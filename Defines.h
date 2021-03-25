#ifndef DEFINES_H_
#define DEFINES_H_

enum AirShipDefines {
  ZERO=0,

  BATTLE_CRUSER_HEALTH = 450,
  BATTLE_BRUSER_DAMAGE = 40,

  VIKING_HEALTH = 150,
  VIKING_DAMAGE = 15,
  VIKING_DAMAGE_VS_PHOENIX = 30,

  CARRIER_HEALTH = 200,
  CARRIER_SHIELD = 150,
  CARRIER_DAMAGE = 8,
  CARRIER_SHIELD_REGENERATE_RATE = 40,

  PHOENIX_HEALTH = 90,
  PHOENIX_SHIELD = 90,
  PHOENIX_DAMAGE = 20,
  PHOENIX_SHIELD_REGENERATE_RATE = 20
};

typedef enum AirShipType {
  BATTLE_CRUSER, VIKING, CARRIER, PHOENIX
}AirShipType;

enum CarrierDefines {
  MAX_INTERCEPTORS = 8,
  DAMAGED_STATUS_INTERCEPTORS = 4
};

enum BattleCruserDefines {
  YAMATO_CANNON_LOADING_TURNS = 4
};

/*Forward declaration of: The ship struct that contains shipType and it's abilities*/
typedef struct Ship Ship;

/*Forward declaration of: the ships abilities*/
typedef struct Abilities Abilities;

/*Forward declaration of: the union that contains the shipType*/
typedef union Ships Ships;


/*Forward declaration of: Viking shipType*/
typedef struct Viking Viking;

/*Forward declaration of: BattleCruser shipType*/
typedef struct BattleCruser BattleCruser;

/*Forward declaration of: Phoenix shipType*/
typedef struct Phoenix Phoenix;

/*Forward declaration of: Carrier shipType*/
typedef struct Carrier Carrier;

#endif /* DEFINES_H_ */
