/*
 * Universal_Types.h
 *
 *  Created on: 30 Jun 2023
 *  Last Updated on: 17 September 2023
 *      Author: Bart Shields
 */

#ifndef UNIVERSAL_TYPES_H_
#define UNIVERSAL_TYPES_H_

  typedef  char                int8_t;
  typedef  short               int16_t;
  typedef  long                int32_t;
  typedef  long long           int64_t;
  typedef  unsigned char       uint8_t;
  typedef  unsigned short      uint16_t;
  typedef  unsigned long       uint32_t;
  typedef  unsigned long long  uint64_t;

#pragma  pack (push, 1)

  /* 32-Bit Overlay Structure */
  typedef union _32_Bit_Overlay {

    uint8_t   _8_Bit_Overlay_Array [4];
    uint16_t  _16_Bit_Overlay_Array [2];
    uint32_t  _32_Bit_LongValue;

  } _32_Bit_Overlay_type;

  typedef struct Balanced_Binary_Tree {

      /* Fields needed for keeping a balanced binary tree. */
      int32_t   balance_factor;  /*  -1, 0, or +1            */

      /* NOTE: the user of this structure should be very careful in setting and/or accessing
       * the owning data structure via these fields */
      void  *  parent_node_ptr;  /* A NULL_PTR value indicates this is the ROOT node. */
      void  *  left_subtree_ptr;
      void  *  right_subtree_ptr;

  } Balanced_Binary_Tree_t;

#pragma pack (pop)


#endif /* UNIVERSAL_TYPES_H_ */
