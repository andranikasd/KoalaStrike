# Angry-Coalla
> Basic packet sniffer writen in c lang
> ARP spoofing: A hacker sends fake ARP packets that link an attacker's MAC address with an IP of a computer already on the LAN. 

## ARP HEADER 
Hardware type (HTYPE)
    This field specifies the network link protocol type. Example: Ethernet is 1.[2]
Protocol type (PTYPE)
    This field specifies the internetwork protocol for which the ARP request is intended. For IPv4, this has the value 0x0800. The permitted PTYPE values share a numbering space with those for EtherType.[2][3]
Hardware length (HLEN)
    Length (in octets) of a hardware address. Ethernet address length is 6.
Protocol length (PLEN)
    Length (in octets) of internetwork addresses. The internetwork protocol is specified in PTYPE. Example: IPv4 address length is 4.
Operation
    Specifies the operation that the sender is performing: 1 for request, 2 for reply.
Sender hardware address (SHA)
    Media address of the sender. In an ARP request this field is used to indicate the address of the host sending the request. In an ARP reply this field is used to indicate the address of the host that the request was looking for.
Sender protocol address (SPA)
    Internetwork address of the sender.
Target hardware address (THA)
    Media address of the intended receiver. In an ARP request this field is ignored. In an ARP reply this field is used to indicate the address of the host that originated the ARP request.
Target protocol address (TPA)
    Internetwork address of the intended receiver.

## TODO: 
- ARP POISONING ATTACK
- Identify targets 
- Create entrys for arp positionig 
- We need to present ourself as router for host target and as host for router target 
- Create custom packet to send to targets
- 







## ARP POSITIONING ATTACK 
