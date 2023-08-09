#include "../include/network.h"
#include "../include/logging.h"

int main() {
    arp_header arp_hdr = {
        0x0001, 0x0800, 6, 4, 1,
        {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF},
        {192, 168, 1, 1},
        {0x00, 0x11, 0x22, 0x33, 0x44, 0x55},
        {192, 168, 1, 2}
    };    
 
    print_arp_header(&arp_hdr);
    return 0;
}