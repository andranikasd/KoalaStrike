# KoalaStrike 
> ARP spoofing tool implemented in c programming language 

## What is ARP spoofing?
ARP spoofing, ARP cache poisoning, or ARP poison routing is a technique by which an attacker sends (spoodef) Addres resolution Protocol (ARP) messages onto a local area network. The aim is to associate the attacker's MAC address with the OP address of another host, such as the default gateway, causing any traffic meant for that IP address to be sent to the attacker instead. [Wiki](https://en.wikipedia.org/wiki/ARP_spoofing)


![ARP spoofing image:][arp_spoofing]

[arp_spoofing]: https://upload.wikimedia.org/wikipedia/commons/3/33/ARP_Spoofing.svg

## Detecting ARP Spoofing attack
> To see more about how to detect ARP Spoofing Go see ["Network Security Hack" by Andrew Lochart](https://edu.anarcho-copy.org/GNU%20Linux%20-%20Unix-Like/network-security-hacks.pdf) 

One program that can help accomplish this is [Arpwatch](ftp://ftp.ee.lbl.gov/arpwatch.tar.gz). It works by monitoring an interface in promiscuous mode
and recording MAC/IP address pairings over a period of time. When it sees anomalous behavior,such as a change to one of the MAC/IP pairs that it has learned, it will send an alert to the syslog.
This can be very effective in a shared network using a hub, since a single machine can monitor all
ARP traffic. However, due to the unicast nature of ARP responses, this program will not work as
well on a switched network.
To achieve the same level of detection coverage in a switched environment, Arpwatch should be
installed on as many machines as possible. After all, you can't know with 100% certainty what
hosts an attacker will decide to target. If you're lucky enough to own one, many high-end
switches allow you to designate a monitor port that can see the traffic of all other ports. If you
have such a switch, you can install a server on that port for network monitoring, and simply run
Arpwatch on it.

After downloading Arpwatch, you can compile and install it in the usual manner by running:

```sh
# ./configure && make && make install
```

When running Arpwatch on a machine with multiple interfaces, you'll probably want to specify
the interface on the command line. This can be done by using the ```-i``` command-line option:

```sh
arpwatch -i iface
```

As Arpwatch begins to learn the MAC/IP pairings on your network, you'll see log entries similar to
this:

```sh
Nov 1 00:39:08 zul arpwatch: new station 192.168.0.65 0:50:ba:85:85:ca
```


When a MAC/IP address pair changes, you should see something like this:

```sh
Nov 1 01:03:23 zul arpwatch: changed ethernet address 192.168.0.65 0:e0:81:3:d8:8e
(0:50:ba:85:85:ca)
Nov 1 01:03:23 zul arpwatch: flip flop 192.168.0.65 0:50:ba:85:85:ca (0:e0:81:3:d8:8e)
Nov 1 01:03:25 zul arpwatch: flip flop 192.168.0.65 0:e0:81:3:d8:8e (0:50:ba:85:85:ca)
```

In this case, the initial entry is from the first fraudulent ARP response that was received, and the
subsequent two are from a race condition between the fraudulent and authentic responses.
To make it easier to deal with multiple Arpwatch installs on a switched environment, you can
send the log messages to a central ```syslogd```, aggregating all the output into one
place. However, due to the fact that your machines can be manipulated by the same attacks that
Arpwatch is looking for, it would be wise to use static ARP table entries [Hack #32] on your
syslog server, as well as all the hosts running Arpwatch.
