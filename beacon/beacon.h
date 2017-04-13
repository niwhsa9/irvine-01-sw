#ifndef __BEACON_HH__
#define __BEACON_HH__

#include <polysat_pkt/sys_manager_structs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BEACON_ID "IRV-01"
#define ID_LEN 7

/**
 * Packet needs to fit in 227 bytes
 **/
typedef struct {
  char id[ID_LEN]; /* "IRV-01" To make it easy recognize           */

  uint16_t ldc;    /* Long Duration Timer (about 4min 15 sec/tick) */

  int32_t gyro[3]; 
  int32_t mag[3];  
  uint16_t daughter_aTmpSensor;
  uint16_t threeV_plTmpSensor;
  uint16_t tempNz;

  /* Power Data is 8 bytes */
  /*
   * uint32_t volt
   * int32_t current
   */
  struct PowerData threeVPwrSensor;
  struct PowerData fiveV_plPwrSensor;

  // TODO:  Add DSA release/deployment state
} __attribute__((packed)) BeaconData;

#ifdef __cplusplus
}
#endif

#endif
