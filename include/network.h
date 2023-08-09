#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

#define HARDWARE_LENGTH       6   // LENGTH of MAC address
#define HARDWARE_TYPE_ETHER   1   // To send in eth interface

#define BROADCAST_MAC (uint8_t[]) {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} // Broadcast MAC address

#define PROTOCOL_LENGTH       4   // LENGTH of IP address

#define OPCODE_REQUEST        1   // ARP operation code for request
#define OPCODE_REPLY          2   // ARP operation code for reply

// ETHERNET header definition
typedef struct __attribute__ ((__packed__)) {
    uint8_t dst_host[HARDWARE_LENGTH] : BROADCAST_MAC;
    uint8_t src_host[HARDWARE_LENGTH];
    uint16_t ethernet_type;
}ethernet_header;

// ARP header definition
typedef struct __attribute__ ((__packed__)) {
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t hardware_length : HARDWARE_LENGTH;
    uint8_t protocol_length : PROTOCOL_LENGTH;
    uint16_t operation_code;
    uint8_t src_hardware_addr[HARDWARE_LENGTH];
    uint8_t src_protocol_addr[PROTOCOL_LENGTH];
    uint8_t dst_hardware_addr[HARDWARE_LENGTH];
    uint8_t dst_protocol_addr[PROTOCOL_LENGTH];
}arp_header;

#endif