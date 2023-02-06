#ifndef NET_HELPER_H
#define NET_HELPER_H
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#include <Network/net_defines.h>
#include <Log/logger.h>

// Global
int socket_creator(int domain, int type, int protocol);

// Mostly server-side
void bind_socket(int h_socket, struct sockaddr* addr, int addr_len);
void server_listen(int h_socket, int backlog);
int accept_client(int h_socket, struct sockaddr* addr, socklen_t* addr_len);

// Mostly client-side
void connect_to_server(int h_socket, struct sockaddr* addr, socklen_t addr_len);
void send_to_server(int h_socket, char* buf, size_t len);
int recv_from_server(int h_socket, void* buf, size_t len);

// get unique user id
int get_uuid(int& prev_id);

// helpers for getting data from config file
int get_domain(const std::string& domain);
int get_type(const std::string& type);
#endif