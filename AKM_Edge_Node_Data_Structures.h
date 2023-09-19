/*
 * AKM_DataStructures.h
 *
 *  Created on: 30 June 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 *
 *  Description:
 *  Data structures defined within this header file are for use by and from the the perspective of a host AKM edge node device.
 *  These are NOT the data structures that will be used by a provisioning node and/or the backend AKM server.  These data structures
 *  are for the most part subsets of the data that will be maintained within a backend server, proxy server, or other provisioning
 *  device.
 */

#ifndef AKM_EDGE_NODE_DATA_STRUCTURES_H_
#define AKM_EDGE_NODE_DATA_STRUCTURES_H_

#include  "Universal_Types.h"
#include  "AES_Encryption_Info.h"
#include  "HMAC_info.h"
#include  "ASR_Security_Data_Set.h"

  /* Enumeration Types */

  typedef enum AKM_Security_Relationship_Object_Delineator_Enum {

    Ultimate_AKM_Root_Of_Trust_Backend_Server_object,       /* Backend Server */
    Intermediate_AKM_Chain_of_Trust_Proxy_Server_object,    /* Intermediate Proxy Server, and always points to the Intermediate Proxy Server
                                                               that is closest to the affected node within the AKM Root-of-Trust hierarchy */
    Local_AKM_Chain_of_Trust_management_module_object,      /* Local AKM Management Module -- this includes both permanent and temporary local
                                                               AKM Management Modules.  An AKM node's security relationship can only have one
                                                               local AKM Management Module at a time.  Typically, temporary local AKM Management
                                                               Modules are used in "Air  Gapped" AKM security relationships. */
    Portable_AKM_Chain_of_Trust_provisioning_device_object, /* Used by maintenance personnel to update and/or repair existing AKM networks. */
    AKM_Communication_Edge_Node_object,                     /* The is the nominal AKM node and represents a logically distinct AKM Module,
                                                               usually a physical device, but could also be a logical partition of a physical
                                                               device. */
    AKM_Electronic_Image_object,                            /* Electronic Image */
    AKM_Security_Relationship_object                        /* An AKM Security Relationship object represents an AKM Security Relationship */

  }  ASR_Object_Delineator_Enum_t;

  /* Address and/or Identifier Types */

  /* Big Endian/Network Addressing Assumed */

  typedef struct {
    uint64_t  _64_bits_0_through_63;
    uint64_t  _64_bits_64_through_127;
  } AKM_Object_Standard_Address_t;

  typedef struct {
    uint64_t  _64_bits_0_through_63;
    uint64_t  _64_bits_64_through_127;
    uint64_t  _64_bits_128_through_191;
    uint64_t  _64_bits_192_through_255;
  } AKM_Object_Enterprise_256_Bit_Address_t;

  /* AKM Core Types */

  /* Forward References */

  typedef struct  AKM_Info_Object  AKM_Info_Object_t;

  /* Regular Typedefs */

  struct AKM_Info_Object {

      AKM_Object_Standard_Address_t  AKM_Node_Address;

      ASR_Object_Delineator_Enum_t   AKM_Object_Delineator;

      Balanced_Binary_Tree_t         Balanced_Binary_Tree;

  };

  typedef struct AIM_Electronic_Image_Object_Synchronized_Data_Set {

      AKM_Object_Standard_Address_t   AKM_Device_Node_Address;

      AES_128_Bit_Encryption_Key_t    Current_Session_Encryption_Key;
      uint32_t                        Current_Session_Seed_Value;
      HMAC_Key_t                      Current_Session_HMAC_Key;
      SHA_256_HMAC_t                  AIM_Digital_Signature;

  } AIM_Electronic_Image_Object_Synchronized_Data_Set_t;


  /* There is ONLY ever one instance of this object per device or partition */
  typedef struct AKM_Edge_Node_Object {

      AKM_Object_Standard_Address_t                          AKM_Device_Node_Address;

      ASR_Synchronized_Data_Set_t                          * Root_Of_Trust_Backend_Server_SDS;
      ASR_Synchronized_Data_Set_t                          * Chain_of_Trust_Proxy_Server_SDS;     /* Points to the SDS representing the logically closet Proxy Server in the Chain-of-Trust hierarchy. */
      ASR_Synchronized_Data_Set_t                          * Local_Management_Module_object;      /* May be null if no local management module is present */
      ASR_Synchronized_Data_Set_t                          * Portable_Provisioning_Device_object; /* May be null when th ere is not a provisioning device present */

      /* This is a binary tree of all of the AKM Security relationships for a particular node.
       * The key used to sort the binary tree is  */
      ASR_Synchronized_Data_Set_t                          * Communication_Edge_Node_Binary_Tree;

      /* This is a binary tree of all of the AKM objects representing all of electronic images associated with a specific hardware device */
      AIM_Electronic_Image_Object_Synchronized_Data_Set_t  * Electronic_Firmware_Release_Image_object_Binary_Tree;

  } AKM_Edge_Node_Object_t;

#endif /* AKM_DATA_STRUCTURES_H_ */
