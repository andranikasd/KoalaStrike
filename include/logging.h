#include "headers.h"

void print_ethernet_header(const ethernet_header *eth_hdr);
void print_arp_header(const arp_header *arp_hdr);

void print_mac_address(const char* interface_name, constunsigned char* mac_address);
