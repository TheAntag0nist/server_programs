#ifndef NET_DEFINES_H
#define NET_DEFINES_H
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

// Technologies defines
#define IPv4 AF_INET
#define IPv6 AF_INET6
// Connection defines
#define TCP SOCK_STREAM
#define UDP SOCK_DGRAM
#define RAW SOCK_RAW
// Boolean defines
#define true 1
#define false 0

#define TRUE 1
#define FALSE 0

#endif