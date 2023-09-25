/*
 * AKM_Network_Management_Gateway_Data_Structures.h
 *
 *  Created on: 19 September 2023
 *  Last Updated on: 19 September 2023
 *      Author: Bart Shields
 *
 *  Description:
 *  Data structures defined within this header file are for use by and from the perspective of an AKM Network Management Module.
 *  These are the data structures that will be used by a provisioning node as well as the AKM backend server.  Although, the
 *  data structures for the AKM backend server will be purely from the perspective of it being the AKM root of trust.  For the
 *  most part these data structures are supersets of the data structures represented for an AKM Edge Node.
 */

#ifndef AKM_IN_NETWORK_MANAGEMENT_GATEWAY_DATA_STRUCTURES_H
#define AKM_IN_NETWORK_MANAGEMENT_GATEWAY_DATA_STRUCTURES_H

#include  "Universal_Types.h"
#include  "AKM_Common_Data_Structures.h"
#include  "AES_Encryption_Info.h"
#include  "HMAC_info.h"
#include  "ASR_Security_Data_Set.h"

  /* Defines */

  /* Enumeration Types */

  
  /* Address and/or Identifier Types */


  /* Forward References */

  /* Regular Typedefs */

  /* There is ONLY ever one instance of this object per device or partition */
  typedef struct _AKM_IN_NETWORK_MANAGEMENT_GATEWAY_OBJECT { // SizeOf (14,549,904-bytes)
      AKM_OBJECT_STANDARD_128_BIT_ADDRESS                     AKM_Device_Node_Address;                              // Offset:          0 -         15 (        16-bytes)

      ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Root_Of_Trust_Backend_Server_SDS;                     // Offset:         16 -        459 (       444-bytes)
      ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Chain_of_Trust_Proxy_Server_SDS;                      // Offset:        460 -        903 (       444-bytes)

      // Each physical device AKM Local Network Management Module SDS data object is 424-bytes
      // The number of provisioning modules within the local deployment is limited to 512. Thus, this
      // field will be 444-bytes x 32,768, which is, 14,548,992-bytes.                                              // Offset:        904 - 14,549,895 (14,548,992-bytes)
      ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Physical_Device_Edge_Node_object [NUM_OF_PHYSICAL_EDGE_NODES_WITHIN_LOCAL_DEPLOYMENT];

      // This is a binary tree of all of the AKM Security relationships for that this AKM Local Network Management Module
      // The key used to sort the binary tree is the AKM Security Relationship (ASR) Address
      PASR_COMMUNICATION_EDGE_NODE_SYNCHRONIZATION_DATA_SET   Communication_Edge_Node_Binary_Tree;                  // Offset: 14,549,896 - 14,549,899 (         4-bytes)

      // This is a binary tree of all of the AKM objects representing all of electronic images associated
      // with the specific hardware device represented by this data structure.
      PAIM_ELECTRONIC_IMAGE_INFO_OBJECT                       Electronic_Firmware_Release_Image_object_Binary_Tree; // Offset: 14,549,900 - 14,549,903 (         4-bytes)
  } AKM_IN_NETWORK_MANAGEMENT_GATEWAY_OBJECT;


#endif /* AKM_IN_NETWORK_MANAGEMENT_GATEWAY_DATA_STRUCTURES_H */
