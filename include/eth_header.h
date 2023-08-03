//*******************************************************************
// Copyright         : 2023 Andranik Grigoryan
// File Name         : eth_header.h
// Description       : ethernet header definition for packet sniffing attack  
// 
// Revision History  : v1
// ------------------------------------------------------------------
// 04/08/23 	Andranik Grigoryan	
//
//******************************************************************/

#ifndef ETH_HEADER
#define ETH_HEADER
#include <cstdint>
#include <sys/cdefs.h>
#define ETH_ALEN 48 // Size of ethernet addr 

struct ether_addr
{
  u_int8_t ether_addr_octet[ETH_ALEN]; // Ethernet addres octet 
}__attribute__ ((__packed__));

typedef struct {
  uint64_t dest_addr[ETH_ALEN];
  uint64_t source_addr[ETH_ALEN]; 
  uint_fast16_t type; 
}eht_header;

#endif 
