#ifndef SERVER_H
#define SERVER_H
#include "../net_helper/net_helper.h"
#include <pthread.h> 
#include <map>

class server{
private:
    struct sockaddr_in server_addr;
    std::map<int, int> h_clients_sockets;
    int h_server_socket;

    int protocol;
    int domain;
    int type;
    int port;

    void create_socket();
    void bind();
    void listen();
    void accept();

public:
    server();
    ~server();

    void set__settings(int protocol, int domain, int type, int port);

    void set_protocol(int protocol);
    void set_domain(int domain);
    void set_type(int type);
    void set_port(int port);

    void start();
    void stop();
};

#endif