

// Hardware type − Ethernet (0x0001)
// Protocol type − IPv4 (0x0800)
// Hardware address length − 6 bytes
// Protocol address length − 4 bytes
// Operation − Reply (0x0002)
// Sender hardware address − AA:BB:CC:DD:EE:FF (the attacker's MAC address)
// Sender protocol address − 192.168.1.200 (the IP address of a legitimate device on the network)
// Target hardware address − 00:11:22:33:44:55 (the sender's MAC address)
// Target protocol address − 192.168.1.100 (the sender's IP address)



#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <arpa/inet.h>

#define ETH_P_ARP       0x0806  // Addres resoulution packet

#define ETH_HEADER_LENGTH     14
#define ARP_HEADER_LENGTH     28

#define HARDWARE_LENGTH       6   // LENGTH of MAC address
#define HARDWARE_TYPE_ETHER   0x0001   // To send in eth interface

#define BROADCAST_MAC (uint8_t[]) {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF} // Broadcast MAC address

#define PROTOCOL_LENGTH       4   // LENGTH of IP address
#define PROTOCOL_TYPE_IPv4    0x0800 // IPv4 type package 

#define OPCODE_REQUEST        1   // ARP operation code for request
#define OPCODE_REPLY          2   // ARP operation code for reply

// ETHERNET header definition
typedef struct __attribute__ ((__packed__)) {
    uint8_t dst_host[HARDWARE_LENGTH];
    uint8_t src_host[HARDWARE_LENGTH];
    uint16_t ethernet_type;
} ethernet_header;

// ARP header definition
typedef struct __attribute__ ((__packed__)) {
    uint16_t hardware_type;
    uint16_t protocol_type;
    uint8_t hardware_length;
    uint8_t protocol_length;
    uint16_t operation_code;
    uint8_t src_hardware_addr[HARDWARE_LENGTH];
    uint8_t src_protocol_addr[PROTOCOL_LENGTH];
    uint8_t dst_hardware_addr[HARDWARE_LENGTH];
    uint8_t dst_protocol_addr[PROTOCOL_LENGTH];
}arp_header;

arp_header* create_arp_package(uint16_t opcode, uint8_t* src_hardw_addr, uint8_t* src_protocol_addr, uint8_t* dst_hardw_addr, uint8_t* dst_protocol_addr); 
ethernet_header* create_ether_package(uint8_t* dst_host, uint8_t* src_host, uint16_t ethernet_type, arp_header* arp_peyload);

#endif