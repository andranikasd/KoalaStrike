#ifndef NET_HEADERS_H
#define NET_HEADERS_H


#include <stdint.h>
#include <stdint.h>

#define ARP_REQUEST     1
#define ARP_REPLY       2
#define HARDWARE_LENGTH 6
#define IP_LENGTH       4
#define BROADCAST_ADDR  (uint8_t){0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}

typedef struct {
  uint8_t   dest_mac_addr[HARDWARE_LENGTH];
  uint8_t   src_mac_addr[HARDWARE_LENGTH];
  uint16_t  ether_type;
}ether_header;

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


#endif
