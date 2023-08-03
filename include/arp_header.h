//*******************************************************************
// Copyright         : 2023 Andranik Grigoryan
// File Name         : arp_header.h
// Description       : ARP header definition for packet sniffing attack  
// 
// Revision History  : v1
// ------------------------------------------------------------------
// 04/08/23 	Andranik Grigoryan	
//
//******************************************************************/

#ifndef APR_HEADER
#define APR_HEADER
#include <cstdint>
#include <uchar.h>
#pragma once 

typedef struct  {
  uint8_t HTYPE; // Hardware type (8 bits)
  uint16_t PTYPE; // Protocol type (16 bits) 
  uint32_t HLEN;  // Hardware address length (6 bits ~ up to 32bit)
  uint32_t PHLEN;  // Protocol address length (4 digit 32 bit)
  uint64_t OPER; // Operation type
  uint64_t SHA; // Sender Hardware address
  uint64_t SPA; // Sender Protocol address 
  uint64_t THA; // The MAC address of the intended receiver. 6 bytes. 
  uint64_t TPA; // The internetwork address of the intended reciever
} arp_header;  

#endif
