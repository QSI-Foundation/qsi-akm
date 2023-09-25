


/*
 * AKM_Common_Data_Structures.h
 *
 *  Created on: 19 September 2023
 *  Last Updated on: 20 September 2023
 *      Author: Bart Shields
 *
 *  Description:
 *  Data structures defined within this header file are for use by and from the perspective of a host AKM edge node device.
 *  These are NOT the data structures that will be used by a provisioning node and/or the backend AKM server.  These data structures
 *  are for the most part subsets of the data that will be maintained within a backend server, proxy server, or other provisioning
 *  device.
 */

#ifndef AKM_COMMON_DATA_STRUCTURES_H
#define AKM_COMMON_DATA_STRUCTURES_H

#include  "Universal_Types.h"
#include  "AES_Encryption_Info.h"

   /* Defines */

#define  NUM_OF_IN_NETWORK_MANAGEMENT_GATEWAYS_WITHIN_LOCAL_DEPLOYMENT  4096
#define  NUM_OF_INTERMEDIATE_PROXY_SERVERS_WITHIN_LOCAL_DEPLOYMENT      128
#define  NUM_OF_PORTABLE_PROVISIONING_UNITS_WITHIN_LOCAL_DEPLOYMENT     512
#define  NUM_OF_PHYSICAL_EDGE_NODES_WITHIN_LOCAL_DEPLOYMENT             32768

  /* Enumeration Types */
typedef enum _ASR_OBJECT_DELINEATOR_ENUM {

  Ultimate_AKM_Root_Of_Trust_Backend_Server_object,       // Backend Server
  Intermediate_AKM_Chain_of_Trust_Proxy_Server_object,    // Intermediate Proxy Server, and always points to the Intermediate Proxy Server
                                                          // that is closest to the affected node within the AKM Root-of-Trust hierarchy
  Local_AKM_Chain_of_Trust_management_module_object,      // Local AKM Management Module -- this includes both permanent and temporary local
                                                          // AKM Management Modules.  An AKM node's security relationship can only have one
                                                          // local AKM Management Module at a time.  Typically, temporary local AKM Management
                                                          // Modules are used in "Air  Gapped" AKM security relationships. */
  Portable_AKM_Chain_of_Trust_provisioning_device_object, // Used by maintenance personnel to update and/or repair existing AKM networks.
  AKM_Communication_Edge_Node_object,                     // The is the nominal AKM node and represents a logically distinct AKM Module,
                                                          // usually a physical device, but could also be a logical partition of a physical
                                                          // device.
  AKM_Electronic_Image_object,                            // Electronic Image
  
  AKM_Security_Relationship_object                        // An AKM Security Relationship object represents an AKM Security Relationship

}  ASR_OBJECT_DELINEATOR_ENUM;


  // Address and/or Identifier Types

  // Big Endian/Network Addressing Assumed

  typedef struct _AKM_OBJECT_STANDARD_128_BIT_ADDRESS {
    U64  _64_bits_0_through_63;
    U64  _64_bits_64_through_127;
  } AKM_OBJECT_STANDARD_128_BIT_ADDRESS;

   typedef struct _AKM_OBJECT_192_BIT_ADDRESS {
    U64  _64_bits_0_through_63;
    U64  _64_bits_64_through_127;
    U64  _64_bits_128_through_191;
  } AKM_OBJECT_STANDARD_192_BIT_ADDRESS;

  typedef struct _AKM_OBJECT_ENTERPRISE_256_BIT_ADDRESS {
    U64  _64_bits_0_through_63;
    U64  _64_bits_64_through_127;
    U64  _64_bits_128_through_191;
    U64  _64_bits_192_through_255;
  } AKM_OBJECT_ENTERPRISE_256_BIT_ADDRESS;

  // Regular Typedefs

    struct _AKM_INFO_OBJECT { // SizeOf: 36-bytes
      AKM_OBJECT_STANDARD_128_BIT_ADDRESS  AKM_Node_Address;       /* Offset:  0 - 15 (16-bytes) */

      ASR_OBJECT_DELINEATOR_ENUM           AKM_Object_Delineator;  /* Offset: 16 - 19 ( 4-bytes) */

      // Balanced Binary Tree
      // Use Methods defined to manipulate this BT, to ensure only AKM Info
      // Objects are manipulated for nodes connected via this field.
     BALANCED_BINARY_TREE                  Balanced_Binary_Tree;   /* Offset: 20 - 35 (16-bytes) */
  } AKM_INFO_OBJECT, *PAKM_INFO_OBJECT;


  typedef struct _AIM_ELECTRONIC_IMAGE_OBJECT { // SizeOf: 116-bytes
      AKM_OBJECT_STANDARD_128_BIT_ADDRESS  AKM_Device_Node_Address;           // Offset:   0 -  15 (16-bytes)

      AES_128_BIT_ENCRYPTION_KEY           Current_Session_Encryption_Key;    // Offset:  16 -  31 (16-bytes)
      U32                                  Current_Session_Seed_Value;        // Offset:  32 -  35 ( 4-bytes)
      HMAC_KEY                             Current_Session_HMAC_Key;          // Offset:  36 -  67 (32-bytes)
      SHA_256_HMAC                         AIM_Digital_Signature;             // Offset:  68 -  99 (32-bytes)

       // Balanced Binary Tree
      // Use Methods defined to manipulate this BT, to ensure only AKM
      // Electronic Image Info Objects are manipulated for nodes connected via this field.
     BALANCED_BINARY_TREE                  Balanced_Binary_Tree;              // Offset: 100 - 115 (15-bytes)
 } AIM_ELECTRONIC_IMAGE_INFO_OBJECT, *PAIM_ELECTRONIC_IMAGE_INFO_OBJECT;

#endif /* AKM_COMMON_DATA_STRUCTURES_H */
