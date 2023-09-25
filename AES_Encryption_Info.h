/*
 * AES_Encryption_Info.h
 *
 *  Created on: 2 Jul 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 */

#ifndef AES_ENCRYPTION_INFO_H_
#define AES_ENCRYPTION_INFO_H_

#include "Types.h"

  /* Core Types */

  typedef struct _AES_128_BIT_ENCRYPTION_KEY {
      U64  _64_bits_0_through_63;
      U64  _64_bits_64_through_127;
  } AES_128_BIT_ENCRYPTION_KEY, *PAES_128_BIT_ENCRYPTION_KEY;

  typedef struct _AES_192_BIT_ENCRYPTION_KEY {
      U64  _64_bits_0_through_63;
      U64  _64_bits_64_through_127;
      U64  _64_bits_128_through_191;
  } AES_192_BIT_ENCRYPTION_KEY, *PAES_192_BIT_ENCRYPTION_KEY;

  typedef struct _AES_256_BIT_ENCRYPTION_KEY {
      U64  _64_bits_0_through_63;
      U64  _64_bits_64_through_127;
      U64  _64_bits_128_through_191;
      U64  _64_bits_192_through_255;
  } AES_256_BIT_ENCRYPTION_KEY, *PAES_256_BIT_ENCRYPTION_KEY;

#endif /* AES_ENCRYPTION_INFO_H_ */
