/*
 * AKM_DataStructures.h
 *
 *  Created on: 30 June 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 *
 *  Description:
 *  Data structures defined within this header file represent the AKM Security Relatioinship (ASR) Synchornized Data Set (i.e., the SDS).
 *  The ASR SDS represents the security credentials for a specific ASR.  These same security credentials are identical for all nodes within
 *  the SDS.
 */

#ifndef ASR_SECURITY_DATA_SET_DATA_STRUCTURES_H_
#define ASR_SECURITY_DATA_SET_DATA_STRUCTURES_H_

#include  "Universal_Types.h"
#include  "AES_Encryption_Info.h"
#include  "HMAC_info.h"

  /* Enumeration Types */


  /* Address and/or Identifier Types */

  /* Big Endian/Network Addressing Assumed */
  typedef struct {
    uint64_t  _64_bits_0_through_63;
    uint64_t  _64_bits_64_through_127;
  } AKM_Security_Relationship_Identifier_t;


  /* AKM Core Types */

  typedef struct PDV {
      uint8_t  PDV_elements [128];
  } Program_Data_Vector_t;

  /* Forward References */

  typedef struct  AKM_Info_Object            AKM_Info_Object_t; /* In AKM_Edge_Node_Data_Structures.h file */
  typedef struct  ASR_Synchronized_Data_Set  ASR_Synchronized_Data_Set_t;

  /* Regular Typedefs */

  typedef struct SDS_Parameters {
      AES_128_Bit_Encryption_Key_t            Current_Session_Encryption_Key;
      uint32_t                                Current_Session_Seed_Value;
      HMAC_Key_t                              Current_Session_HMAC_Key;
      AES_128_Bit_Encryption_Key_t            Next_Session_Encryption_Key;
      uint32_t                                Next_Session_Seed_Value;
      HMAC_Key_t                              Next_Session_HMAC_Key;
      AES_128_Bit_Encryption_Key_t            Fallback_Recovery_Encryption_Key;
      uint32_t                                Fallback_Recovery_Seed_Value;
      HMAC_Key_t                              Fallback_Recovery_HMAC_Key;
      AES_128_Bit_Encryption_Key_t            Failsafe_Recovery_Encryption_Key;
      uint32_t                                Failsafe_Recovery_Seed_Value;
      HMAC_Key_t                              Failsafe_Recovery_HMAC_Key;

      /* Optional Arbiter Session Security Credentials -- used for dynamic provisioning */
      AES_128_Bit_Encryption_Key_t            Arbiter_Session_Encryption_Key;
      uint32_t                                Arbiter_Session_Seed_Value;
      HMAC_Key_t                              Arbiter_Session_HMAC_Key;

      /* Parameter Data Vector (PDV)*/

      Program_Data_Vector_t                   Parameter_Data_Vector;

  } SDS_Parameters_t;

  /* This structure represents a single Synchronised Data Set (SDS) */
  struct ASR_Synchronized_Data_Set {

      AKM_Security_Relationship_Identifier_t  ASR_Security_Relationship_ID;

      SDS_Parameters_t                        SDS_parameters;

      /* Use Methods defined to manipulate this BT, to ensure only AKM Objects are
       * manipulated for nodes connected via this field. */
      AKM_Info_Object_t                     * Binary_Tree_of_AKM_Objects_within_ASR;

      /* Balanced Binary Tree */
      /* Use Methods defined to manipulate this BT, to ensure only AKM Security
       * Relationships are manipulated for nodes connected via this field. */
      Balanced_Binary_Tree_t                  Balanced_Binary_Tree;

  };


#endif