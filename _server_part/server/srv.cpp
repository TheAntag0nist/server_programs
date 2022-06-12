#include "srv.h"
////////////////////////////////////////////////////////////////
//                      Default handler
////////////////////////////////////////////////////////////////
void* server::default_handler(void* data){
    int socket = ((int*) data)[0];
    int uniq_uid = ((int*) data)[1];
    char* message = new char[128];
	int read_size;

    logger::info("Thread is working");
    printf("\tUser %d was connected to server\n", uniq_uid);

    //Receive a message from client
	while( (read_size = recv(socket, message, 128 , 0)) > 0 ){
		logger::info("Receive message from client");
        // Display the message
        std::string temp_str = message;
        logger::info("Msg -> " + temp_str);

        // Send the message
        if(write(socket, message, (size_t) temp_str.size()) == -1)
            logger::error("Error sending message");
    }

	if(read_size == 0)
		logger::info("Client disconnected");
	else if(read_size == -1)
        logger::error("Receive error");

    delete(message);
    close(socket);
    return 0;
}
////////////////////////////////////////////////////////////////
//                      On init server
////////////////////////////////////////////////////////////////
server::server(){
    protocol = 0;
    domain = 0;
    type  = 0;
    port = 0;

    address = "";
    max_connections = 0;

    h_server_socket = 0;
    server_addr = {0};
}
////////////////////////////////////////////////////////////////
//                      On destroy server
////////////////////////////////////////////////////////////////
server::~server(){
    this->stop();
}
////////////////////////////////////////////////////////////////
//                      Private functions    
////////////////////////////////////////////////////////////////
void server::create_socket(){
    // Create socket
    logger::info("Create server socket");
    h_server_socket = socket_creator(domain, type, protocol);
}

void server::bind(){
    // Get info
    logger::info("Port -> " + std::to_string(port));
    logger::info("IP -> " + address);

    // TODO: Can't use localhost here ( why? unknown error? )
    // * Get IP string as number
    // * inet_pton( domain, address.c_str(), &server_addr.sin_addr);

    // Bind
    logger::info("Bind server socket");
    server_addr.sin_family = domain;
    // ! Important: using INADDR_ANY because converting IP addresses not correctly working (Can't create socket for INADDR_LOOPBACK)
    // TODO: Think about network interfaces 
    server_addr.sin_addr.s_addr = (in_addr_t) htonl(inet_addr(address.c_str()));
    server_addr.sin_port = htons(port);
    bind_socket(h_server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));
}

void server::listen(){
    // Listen
    logger::info("Start listening");
    server_listen(h_server_socket, max_connections);
    logger::info("Waiting for connections...");
}

void server::accept(){
    // Accepting connections
    unsigned long long temp_len = sizeof(struct sockaddr_in);
    void* socket_data = nullptr;
    struct sockaddr_in client;
    int h_client_socket;
    int uuid = 0;

    while((h_client_socket = accept_client(h_server_socket, 
        (struct sockaddr*) &client, (socklen_t*)&temp_len))) {
        logger::info("Accepting connection...");
        
        pthread_t connection_thread;
        socket_data = malloc(sizeof(h_client_socket) * 2);
        ((int*) socket_data)[0] = h_client_socket;
        ((int*) socket_data)[1] = get_uuid(uuid);
        uuid = ((int*) socket_data)[1];

        // Create thread for every connection
        if(pthread_create(&connection_thread, NULL, server::default_handler, socket_data))
            logger::fatal("Can't create connection thread");
        else
            logger::info("Successfully created connection thread");
    }

    logger::info("Stop recieving new connections");
}
////////////////////////////////////////////////////////////////
//                      Setters functions  
////////////////////////////////////////////////////////////////
void server::set_protocol(int protocol){
    this->protocol = protocol;
}

void server::set_domain(int domain){
    this->domain = domain;
}

void server::set_type(int type){
    this->type = type;
}

void server::set_port(int port){
    this->port = port;
}

void server::set__settings(int protocol, int domain, int type, int port){
    this->protocol = protocol;
    this->domain = domain;
    this->type = type;
    this->port = port;
}

void server::set_max_connections(int max_connections){
    this->max_connections = max_connections;
}

void server::set_address(const std::string& address){
    this->address = address;
}
////////////////////////////////////////////////////////////////
//                      Public functions  
////////////////////////////////////////////////////////////////
void server::start(){
    create_socket();
    bind();
    listen();
    accept();
}

void server::stop(){
    if(h_server_socket != 0)
        close(h_server_socket);
}
