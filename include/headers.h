




#ifndef HEADERS_H
#define HEADERS_H
#pragma once

// ARP and ETH headers definition 

/*Definitions:
------------

Define the following for referring to the values put in the TYPE
field of the Ethernet packet header:
        ether_type$XEROX_PUP,
        ether_type$DOD_INTERNET,
        ether_type$CHAOS,
and a new one:
        ether_type$ADDRESS_RESOLUTION.
Also define the following values (to be discussed later):
        ares_op$REQUEST (= 1, high byte transmitted first) and
        ares_op$REPLY   (= 2),
and
        ares_hrd$Ethernet (= 1).

Packet format:
--------------

To communicate mappings from <protocol, address> pairs to 48.bit
Ethernet addresses, a packet format that embodies the Address
Resolution protocol is needed.  The format of the packet follows.

    Ethernet transmission layer (not necessarily accessible to
         the user):
        48.bit: Ethernet address of destination
        48.bit: Ethernet address of sender
        16.bit: Protocol type = ether_type$ADDRESS_RESOLUTION
    Ethernet packet data:
        16.bit: (ar$hrd) Hardware address space (e.g., Ethernet,
                         Packet Radio Net.)
        16.bit: (ar$pro) Protocol address space.  For Ethernet
                         hardware, this is from the set of type
                         fields ether_typ$<protocol>.
         8.bit: (ar$hln) byte length of each hardware address
         8.bit: (ar$pln) byte length of each protocol address
        16.bit: (ar$op)  opcode (ares_op$REQUEST | ares_op$REPLY)
        nbytes: (ar$sha) Hardware address of sender of this
                         packet, n from the ar$hln field.
        mbytes: (ar$spa) Protocol address of sender of this
                         packet, m from the ar$pln field.
        nbytes: (ar$tha) Hardware address of target of this
                         packet (if known).
        mbytes: (ar$tpa) Protocol address of target.


*/
#include <memory.h>
#include <stdlib.h>
#include <stdint.h>

struct eth_header {
  
};

typedef struct {
  uint64_t dest_addr;
  uint64_t source_addr; 
  uint16_t protocol_type; 
  // Eth packet data 
  uint16_t hrd; 
  uint16_t pro; 
  uint8_t hln; 
  uint8_t pln; 
  uint16_t op; 
  uint
}arp_header;

#endif
