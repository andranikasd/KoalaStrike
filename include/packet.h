/*
 *
 *
 *
 *
 *
 *
 *
 *
*/

#ifndef PACKET_H
#define PACKET_H


// http://en.wikipedia.org/wiki/Address_Resolution_Protocol
//   hlen          - Ethernet addresses size is 6.
//   plen          - IPv4 address size is 4.
//   frtype        - 0x0806 = ARP - http://en.wikipedia.org/wiki/EtherType
//   htype         - Ethernet is 1.
//   Protocol type - for IPv4, this has the value 0x0800
//   Operation     - specifies the operation that the sender is performing: 1 for request, 2 for reply.

#include <stdint.h>

#define IP_LENGTH 4
#define HARDWARE_LENGTH 6
#define ARP_HEADER_LENGTH 28
#define ETH_HEADER_LENGTH 14

// Ethernet packet definition 
typedef struct {
  uint8_t destination_mac_addr[HARDWARE_LENGTH];
  uint8_t src_mac_addr[IP_LENGTH];
  uint16_t ether_type; 
}eth_packet;

// ARP packet definition
typedef struct {
  uint16_t	hardware_type;
  uint16_t	protocol_type;
  uint8_t	hardware_len;
  uint8_t	protocol_len;
  uint16_t	opcode;
  uint8_t	sender_mac[HARDWARE_LENGTH];
  uint8_t	sender_ip[IP_LENGTH];
  uint8_t	target_mac[HARDWARE_LENGTH];
  uint8_t	target_ip[IP_LENGTH];
}arp_packet;

arp_packet* create_arp_packet (const uint16_t opcode, );
eth_packet* create_eth_packet (const uint8_t* src_mac_addr, const uint8_t* dest_mac_addr, const arp_packet* arp_peyload);
#endif 
