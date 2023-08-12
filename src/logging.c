// #define ERROR 1
#include "../include/logging.h"

void print_ethernet_header(const ethernet_header *eth_hdr) {
    printf("Ethernet Header:\n");
    printf("  Destination Host: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_hdr->dst_host[0], eth_hdr->dst_host[1], eth_hdr->dst_host[2],
           eth_hdr->dst_host[3], eth_hdr->dst_host[4], eth_hdr->dst_host[5]);
    printf("  Source Host:      %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_hdr->src_host[0], eth_hdr->src_host[1], eth_hdr->src_host[2],
           eth_hdr->src_host[3], eth_hdr->src_host[4], eth_hdr->src_host[5]);
    printf("  Ethernet Type:    0x%04X\n", eth_hdr->ethernet_type);
}

void print_arp_header(const arp_header *arp_hdr) {
    printf("ARP Header:\n");
    printf("  Hardware Type:     0x%04X\n", arp_hdr->hardware_type);
    printf("  Protocol Type:     0x%04X\n", arp_hdr->protocol_type);
    printf("  Hardware Length:   %u\n", arp_hdr->hardware_length);
    printf("  Protocol Length:   %u\n", arp_hdr->protocol_length);
    printf("  Operation Code:    0x%04X\n", arp_hdr->operation_code);
    printf("  Source Hardware Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           arp_hdr->src_hardware_addr[0], arp_hdr->src_hardware_addr[1],
           arp_hdr->src_hardware_addr[2], arp_hdr->src_hardware_addr[3],
           arp_hdr->src_hardware_addr[4], arp_hdr->src_hardware_addr[5]);
    printf("  Source Protocol Address: %u.%u.%u.%u\n",
           arp_hdr->src_protocol_addr[0], arp_hdr->src_protocol_addr[1],
           arp_hdr->src_protocol_addr[2], arp_hdr->src_protocol_addr[3]);
    printf("  Destination Hardware Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           arp_hdr->dst_hardware_addr[0], arp_hdr->dst_hardware_addr[1],
           arp_hdr->dst_hardware_addr[2], arp_hdr->dst_hardware_addr[3],
           arp_hdr->dst_hardware_addr[4], arp_hdr->dst_hardware_addr[5]);
    printf("  Destination Protocol Address: %u.%u.%u.%u\n",
           arp_hdr->dst_protocol_addr[0], arp_hdr->dst_protocol_addr[1],
           arp_hdr->dst_protocol_addr[2], arp_hdr->dst_protocol_addr[3]);
}

void print_mac_address(const unsigned char* mac_address) {
    printf(
       "MAC address is: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
       mac_address[0],
       mac_address[1],
       mac_address[2],
       mac_address[3], 
       mac_address[4],
       mac_address[5]
    );
}