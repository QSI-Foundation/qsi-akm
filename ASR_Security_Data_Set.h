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

#include  "Types.h"
#include  "AES_Encryption_Info.h"
#include  "HMAC_info.h"

  // Enumeration Types


  // Address and/or Identifier Types

  // Big Endian/Network Addressing Assumed
  typedef _AKM_SECURITY_RELATIONSHIP_IDENTIFIER {
    U64  _64_bits_0_through_63;
    U64  _64_bits_64_through_127;
  } AKM_SECURITY_RELATIONSHIP_IDENTIFIER;


  // AKM Core Types

  typedef struct _PROGRAM_DATA_VECTOR {
      U8  PDV_elements [128];
  } PROGRAM_DATA_VECTOR, *PPROGRAM_DATA_VECTOR;

  // Forward References

  typedef struct  _AKM_INFO_OBJECT  AKM_INFO_OBJECT; // In AKM_Edge_Node_Data_Structures.h file

  // Regular Typedefs

  typedef struct _SDS_PARAMETERS {
      AKM_SECURITY_RELATIONSHIP_IDENTIFIER  ASR_Security_Relationship_ID;     // Offset:   0 -  15 (16-bytes)

      AES_128_BIT_ENCRYPTION_KEY            Current_Session_Encryption_Key;   // Offset:  16 -  31 (16-bytes)
      U32                                   Current_Session_Seed_Value;       // Offset:  32 -  35 ( 4-bytes)
      HMAC_KEY                              Current_Session_HMAC_Key;         // Offset:  36 -  67 (32-bytes)
      AES_128_BIT_ENCRYPTION_KEY            Next_Session_Encryption_Key;      // Offset:  68 -  83 (16-bytes)
      U32                                   Next_Session_Seed_Value;          // Offset:  84 -  87 ( 4-bytes)
      HMAC_KEY                              Next_Session_HMAC_Key;            // Offset:  88 - 119 (32-bytes)
      AES_128_BIT_ENCRYPTION_KEY            Fallback_Recovery_Encryption_Key; // Offset: 120 - 135 (16-bytes)
      U32                                   Fallback_Recovery_Seed_Value;     // Offset: 136 - 139 ( 4-bytes)
      HMAC_KEY                              Fallback_Recovery_HMAC_Key;       // Offset: 140 - 171 (32-bytes)
      AES_128_BIT_ENCRYPTION_KEY            Failsafe_Recovery_Encryption_Key; // Offset: 172 - 187 (16-bytes)
      U32                                   Failsafe_Recovery_Seed_Value;     // Offset: 188 - 191 ( 4-bytes)
      HMAC_KEY                              Failsafe_Recovery_HMAC_Key;       // Offset: 192 - 223 (32-bytes)

      // Optional Arbiter Session Security Credentials -- used for dynamic provisioning
      AES_128_BIT_ENCRYPTION_KEY            Arbiter_Session_Encryption_Key;   // Offset: 224 - 239 (16-bytes)
      U32                                   Arbiter_Session_Seed_Value;       // Offset: 240 - 243 ( 4-bytes)
      HMAC_KEY                              Arbiter_Session_HMAC_Key;         // Offset: 244 - 275 (32-bytes)

      // Parameter Data Vector (PDV)
      PROGRAM_DATA_VECTOR                   Parameter_Data_Vector;            // Offset: 276 - 403 (128-bytes) */
  } SDS_PARAMETERS, *PSDS_PARAMETERS;


  // This structure represents a single Synchronised Data Set (SDS) for physical device AKM provisioning modules
  // and is always organized from the perspective of the chain of trust.  The AKM Object representing the
  // AKM Provisioner is always higher on the chain of trust than the object representing the AKM Provisionee.
typedef struct _ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET {
  SDS_PARAMETERS                       SDS_parameters;                    // Offset:   0 - 403 (404-bytes)

  // As of this writing, this should be one of the following values:
  //
  //    Ultimate_AKM_Root_Of_Trust_Backend_Server_object,
  //    Intermediate_AKM_Chain_of_Trust_Proxy_Server_object,
  //    Local_AKM_Chain_of_Trust_management_module_object,
  //    Portable_AKM_Chain_of_Trust_provisioning_device_object,
  ASR_OBJECT_DELINEATOR_ENUM           AKM_Provisioner_Object_Delineator; // Offset: 420 - 423 ( 4-bytes)
  AKM_OBJECT_STANDARD_128_BIT_ADDRESS  Provisioning_Module_AKM_Address;   // Offset: 404 - 419 (16-bytes)

  // As of this writing, this can be one of the following values:
  //
  //    Intermediate_AKM_Chain_of_Trust_Proxy_Server_object,
  //    Local_AKM_Chain_of_Trust_management_module_object,
  //    Portable_AKM_Chain_of_Trust_provisioning_device_object,
  //    AKM_Communication_Edge_Node_object
  ASR_OBJECT_DELINEATOR_ENUM           AKM_Provisionee_Object_Delineator;             // Offset: 420 - 423 ( 4-bytes)
  AKM_OBJECT_STANDARD_128_BIT_ADDRESS  Subservient_Object_AKM_Address;   // Offset: 404 - 419 (16-bytes)

} ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET, *PASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET;


  // This structure represents a single Synchronised Data Set (SDS) for AKM Communication Edge Nodes
struct ASR_Communication_Edge_Node_Synchronized_Data_Set {
   SDS_PARAMETERS        SDS_parameters;                        // Offset:   0 - 403 (404-bytes)

   // Use Methods defined to manipulate this BT, to ensure only AKM Objects are
   // manipulated for nodes connected via this field.
   PAKM_INFO_OBJECT      Binary_Tree_of_AKM_Objects_within_ASR; // Offset: 404 - 407 (  4-bytes)

   // Balanced Binary Tree */
   // Use Methods defined to manipulate this BT, to ensure only AKM Security
   // Relationships are manipulated for nodes connected via this field.
   BALANCED_BINARY_TREE  Balanced_Binary_Tree;                  // Offset: 408 - 423 ( 16-bytes)
} ASR_COMMUNICATION_EDGE_NODE_SYNCHRONIZATION_DATA_SET, *PASR_COMMUNICATION_EDGE_NODE_SYNCHRONIZATION_DATA_SET;


#endif