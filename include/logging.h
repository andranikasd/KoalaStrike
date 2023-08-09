#include <stdio.h>
#include "network.h"

void print_ethernet_header(const ethernet_header *eth_hdr);
void print_arp_header(const arp_header *arp_hdr);