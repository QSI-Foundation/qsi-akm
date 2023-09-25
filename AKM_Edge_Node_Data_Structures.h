/*
 * AKM_Edge_Node_DataStructures.h
 *
 *  Created on: 30 June 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 *
 *  Description:
 *  Data structures defined within this header file are for use by and from the perspective of a host AKM edge node device.
 *  These are NOT the data structures that will be used by a provisioning node and/or the backend AKM server.  These data structures
 *  are for the most part subsets of the data that will be maintained within a backend server, proxy server, or other provisioning
 *  device.
 */

#ifndef AKM_EDGE_NODE_DATA_STRUCTURES_H_
#define AKM_EDGE_NODE_DATA_STRUCTURES_H_

#include  "Types.h"
#include  "AKM_Common_Data_Structures.h"
#include  "AES_Encryption_Info.h"
#include  "HMAC_info.h"
#include  "ASR_Security_Data_Set.h"

  // Enumeration Types

  // AKM Core Types

  // Forward References

  // Regular Typedefs

  // There is ONLY ever ONE instance of this object per device or partition
  // Each Physical Device will need no less than 220,095 bytes to represent its own object data structure,
  // because it has to keep provisioning relationships for up to 512 separate portable provisioning devices
  // that could be used to initialize it.
  typedef struct _AKM_EDGE_NODE_OBJECT { // SizeOf: 230,032-bytes
     AKM_OBJECT_STANDARD_128_BIT_ADDRESS                     AKM_Device_Node_Address;                              // Offset:       0 -      15 (     16-bytes)

     ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Root_Of_Trust_Backend_Server_SDS;                     // Offset:      16 -     459 (    444-bytes)
     ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Chain_of_Trust_Proxy_Server_SDS;                      // Offset:     460 -     903 (    444-bytes )
     /* If there is no local management module, this will be a duplicate of the Proxy Server SDS */
     ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Local_Network_Management_Module_object;               // Offset:     904 -   1,347 (    444-bytes)

     // Each physical device AKM Provisioning Module SDS data object is 424-bytes
     // The number of provisioning modules within the local deployment is limited to 512. Thus, this
     // field will be 424-bytes x 512, which is, 218,800-bytes.                                                    // Offset:   1,348 - 230,023 (228,676-bytes)
     ASR_PHYSICAL_DEVICE_PROVISIONING_SYNCHRONIZED_DATA_SET  Portable_Provisioning_Device_object [NUM_OF_PROVISIONING_MODULES_WITHIN_LOCAL_DEPLOYMENT];

     // This is a binary tree of all of the AKM Security relationships for a particular  communication
     // edge node The key used to sort the binary tree is the AKM Security Relationship (ASR) Address
     PASR_COMMUNICATION_EDGE_NODE_SYNCHRONIZATION_DATA_SET   Communication_Edge_Node_Binary_Tree;                  // Offset: 230,024 - 230,027 (      4-bytes)

     // This is a binary tree of all of the AKM objects representing all of electronic images associated
     // with the specific hardware device represented by this data structure.
     PAIM_ELECTRONIC_IMAGE_OBJECT                            Electronic_Firmware_Release_Image_object_Binary_Tree; // Offset: 230,028 - 230,031 (      4-bytes)
  } AKM_EDGE_NODE_OBJECT, *PAKM_EDGE_NODE_OBJECT;

#endif /* AKM_DATA_STRUCTURES_H_ */
