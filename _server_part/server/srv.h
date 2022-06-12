#ifndef SERVER_H
#define SERVER_H
#include "../../net_helper/net_helper.h"
#include <pthread.h> 
#include <map>

typedef void* (*pthread_func_t)(void*);

class server{
private:
    struct sockaddr_in server_addr;
    std::map<int, int> h_clients_sockets;
    int h_server_socket;

    int protocol;
    int domain;
    int type;
    int port;

    std::string address;
    int max_connections;

    pthread_func_t handler;

    void create_socket();
    void bind();
    void listen();
    void accept();

    static void* default_handler(void* data);

public:
    server();
    ~server();

    void set__settings(int protocol, int domain, int type, int port);

    void set_protocol(int protocol);
    void set_domain(int domain);
    void set_type(int type);
    void set_port(int port);

    void set_max_connections(int max_connections);
    void set_address(const std::string& address);

    void set_access_func(pthread_func_t function);

    void start();
    void stop();
};
#endif