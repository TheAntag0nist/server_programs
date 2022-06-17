#include "net_helper.h"

int socket_creator(int domain, int type, int protocol){
    int h_socket = socket(domain, type, protocol);
    if(h_socket == -1)
        logger::fatal("Can't create socket");
    return h_socket;
}

void bind_socket(int h_socket, struct sockaddr* addr, int addr_len){
    int res = bind(h_socket, addr, addr_len);
    if(res < 0)
        logger::fatal("Can't bind socket");
    return;
}

void server_listen(int h_socket, int backlog){
    int res = listen(h_socket, backlog);
    if(res < 0)
        logger::fatal("Can't listen on socket");
    return;
}

int accept_client(int h_socket, struct sockaddr* addr, socklen_t* addr_len){
    int h_result_socket = accept(h_socket, addr, addr_len);
    if(h_result_socket < 0)
        logger::fatal("Can't accept socket");

    return h_result_socket;
}

void connect_to_server(int h_socket, struct sockaddr* addr, socklen_t addr_len){
    int result = connect(h_socket, addr, addr_len);
    if(result == -1)
        logger::fatal("Can't connect to server");
    return;
}

void send_to_server(int h_socket, char* buf, size_t len){
    int result = send(h_socket, buf, len, 0);
    if(result == -1)
        logger::error("Can't send to server");
    return;
}

int recv_from_server(int h_socket, void* buf, size_t len){
    int result = recv(h_socket, buf, len, 0);
    if(result == 0)
        logger::fatal("Disconnected from server (ERROR 5xx)");
    if(result == -1)
        logger::error("Can't recv from server (ERROR 4xx)");
    return result;
}

int get_uuid(int& prev_id){
    return prev_id + rand() % 9999 + 1;
}

int get_domain(const std::string& domain){
    if(domain == "IPv4")
        return IPv4;
    if(domain == "IPv6")
        return IPv6;
    
    return -1;
}

int get_type(const std::string& type){
    if(type == "TCP")
        return TCP;
    if(type == "UDP")
        return UDP;

    return -1;
}
