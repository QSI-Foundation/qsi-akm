/*
 * HMAC_info.h
 *
 *  Created on: 2 Jul 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 */

#ifndef COMMON_INCLUDE_HMAC_INFO_H_
#define COMMON_INCLUDE_HMAC_INFO_H_

#include "Universal_Types.h"

 typedef struct SHA_256_HMAC {

      uint8_t  SHA_256_Byte_Array [32];

  } SHA_256_HMAC_t;

 typedef struct SHA_512_HMAC {

      uint8_t  SHA_512_Byte_Array [64];

  } SHA_256_HMAC_t;

  /* Default Size of HMAC is 256-bits */
  typedef SHA_256_HMAC_t  HMAC_Key_t;

 
#endif /* COMMON_INCLUDE_HMAC_INFO_H_ */
