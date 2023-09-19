/*
 * AES_Encryption_Info.h
 *
 *  Created on: 2 Jul 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 */

#ifndef AES_ENCRYPTION_INFO_H_
#define AES_ENCRYPTION_INFO_H_

#include "Universal_Types.h"

  /* Core Types */

  typedef struct {
      uint64_t  _64_bits_0_through_63;
      uint64_t  _64_bits_64_through_127;
  } AES_128_Bit_Encryption_Key_t;

  typedef struct {
      uint64_t  _64_bits_0_through_63;
      uint64_t  _64_bits_64_through_127;
      uint64_t  _64_bits_128_through_191;
  } AES_192_Bit_Encryption_Key_t;

  typedef struct {
      uint64_t  _64_bits_0_through_63;
      uint64_t  _64_bits_64_through_127;
      uint64_t  _64_bits_128_through_191;
      uint64_t  _64_bits_192_through_255;
  } AES_256_Bit_Encryption_Key_t;

#endif /* AES_ENCRYPTION_INFO_H_ */
