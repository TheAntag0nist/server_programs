#ifndef CLIENT_H
#define CLIENT_H
#include <Network/net_helper.h>
#include <Package/package.h>
#include <pthread.h> 

class client{
private:
	struct sockaddr_in server_connection = {0};
    int h_client_socket;

    int protocol;
    int domain;
    int type;

    package client_package;
    pthread_t server_answers_thread;
    std::string server_ip;
    int port;

    void create_socket();
    void connect();
    void main();

    static void* on_recieve(void* data);

public:
    client();
    ~client();

    void set_settings(int protocol, int domain, int type, int port);
    void set_protocol(int protocol);
    void set_domain(int domain);
    void set_type(int type);
    void set_port(int port);

    void set_address(const std::string& address);

    void start();
    void stop();
};

#endif