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

 typedef struct _SHA_256_HMAC {

      U8  SHA_256_Byte_Array [32];

  } SHA_256_HMAC;

 typedef struct _SHA_512_HMAC {

      U8  SHA_512_Byte_Array [64];

  } SHA_512_HMAC;

  /* Default Size of HMAC is 256-bits */
  typedef  SHA_256_HMAC  HMAC_KEY;

 
#endif /* COMMON_INCLUDE_HMAC_INFO_H_ */
