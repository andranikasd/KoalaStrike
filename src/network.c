#include "../include/net_headers.h"
#include <stdint.h>
#include <sys/socket.h>
#include <stdlib.h>

/*
typedef struct {
  uint16_t  hardware_type;
  uint16_t  protocol_type;
  uint8_t   hardware_len;
  uint8_t   protocol_len;
  uint16_t  operation_code;
  uint8_t   sender_mac_addr[HARDWARE_LENGTH];
  uint8_t   target_mac_addr[HARDWARE_LENGTH];
  uint8_t   target_ip_addr[IP_LENGTH];
}arp_header;
*/

arp_header* arp_packet(const uint16_t opcode, const uint8_t *src_mac_addr, const char *spoofed_ip_source, const uint8_t *dest_mac_addr, const uint8_t *dest_ip) {
  
  uint16_t* hardware_type = (uint16_t)malloc(sizeof(uint16_t)); 
  uint16_t* protocol_type = (uint16_t)malloc(sizeof(uint16_t));
  uint8_t* hardware_len = (uint8_t)malloc(sizeof(uint8_t));
  uint8_t* protocol_len = (uint8_t)malloc(sizeof(uint8_t)); 
  uint16_t operation_code = opcode;
  uint8_t* sender_mac_addr = src_mac_addr;
  uint8_t* target_mac_addr = dest_mac_addr;
  uint8_t* target_ip_addr = dest_ip; 

  arp_header* packet = (uint16_t)malloc(sizeof(uint16_t)) 
                     + (uint16_t)malloc(sizeof(uint16_t))
                     + (uint8_t)malloc(sizeof(uint8_t))
                     + (uint16_t)malloc(sizeof(uint16_t))
                     +  (uint8_t)malloc(sizeof(uint8_t))
                     + (uint8_t)malloc(sizeof(uint8_t) * HARDWARE_LENGTH)
                     + (uint8_t)malloc(sizeof(uint8_t) * HARDWARE_LENGTH)
                     + (uint8_t)malloc(sizeof(uint8_t) * IP_LENGTH);

  packet->operation_code = opcode;
  packet->sender_mac_addr = src_mac_addr;
  packet->target_ip_addr = spoofed_ip_source;
  packet->target_mac_addr = dest_mac_addr;
  // packet->target_ip_addr = dest_ip;
  
  // TODO: Add all definitions for packet


  return packet;
}

// TODO: Finish ethernet header constructor 
ether_header* eth_packet(const uint8_t *dest_mac_addr, const uint8_t *src_mac_addr, const arp_header *arp_peyload) {}

