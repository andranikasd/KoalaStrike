#include "../include/network.h"
#include "../include/logging.h"
#include <stdlib.h>
#include <string.h>



arp_header* create_arp_package(uint16_t opcode, uint8_t* src_hardw_addr, uint8_t* src_protocol_addr,
                               uint8_t* dst_hardw_addr, uint8_t* dst_protocol_addr) 
                            
{       
    arp_header* arp_packet;

    // In case of memory allocation error 
    if(!(arp_packet = malloc(sizeof(arp_header))))
        return NULL;

    // Initializing statical values 
    arp_packet->hardware_type = htons(HARDWARE_TYPE_ETHER);
    arp_packet->protocol_type = htons(PROTOCOL_TYPE_IPv4);
    arp_packet->hardware_length = HARDWARE_LENGTH;
    arp_packet->protocol_length = PROTOCOL_LENGTH;
    arp_packet->operation_code = htons(opcode);
    
    // Initializing dynamic fetched values 
    memcpy(&arp_packet->src_hardware_addr, src_hardw_addr, sizeof(uint8_t) * HARDWARE_LENGTH);
    memcpy(&arp_packet->dst_hardware_addr, dst_hardw_addr, sizeof(uint8_t) * HARDWARE_LENGTH);

    if(inet_pton(AF_INET, src_protocol_addr, arp_packet->src_protocol_addr) != 1 ||
     inet_pron(AF_INET, dst_protocol_addr, arp_packet->dst_protocol_addr) != 1)
        return NULL;

    return (arp_packet);
}

ethernet_header* create_ether_package(uint8_t* dst_host, uint8_t* src_host, uint16_t ethernet_type, arp_header* arp_peyload) {
    ethernet_header* eth_header;

    if(!(eth_header = malloc(sizeof(ethernet_header))))
        return NULL;

    // Initializing values 
    memcpy(&eth_header->dst_host, dst_host, sizeof(uint8_t) * HARDWARE_LENGTH);
    memcpy(&eth_header->src_host, src_host, sizeof(uint8_t) * HARDWARE_LENGTH);
    // memcpy(&eth_header->ethernet_type, ,sizeof(uint16_t));

    uint8_t arp_ident_first_byte    = ethernet_type / 256;
    uint8_t arp_idnet_second_byte  = ethernet_type % 256; 

    memcpy(&eth_header->ethernet_type, (uint8_t[2]){arp_ident_first_byte, arp_idnet_second_byte}, sizeof(uint8_t) * 2);

    // Filling peyload of arp and eht header continuesly in heap 
    memcpy((uint8_t* )eth_header + ETH_HEADER_LENGTH, arp_peyload, sizeof(uint8_t) * ARP_HEADER_LENGTH);

    return (eth_header);
}