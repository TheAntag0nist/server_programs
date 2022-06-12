#include "clnt.h"
////////////////////////////////////////////////////////////////
//                      Private functions    
////////////////////////////////////////////////////////////////
client::client(){
    server_connection = {0};
    h_client_socket = 0;

    protocol = 0;
    domain = 0;
    type = 0;
    port = 0;

    server_ip = "";
}

client::~client(){
    this->stop();
}

void client::create_socket(){
    logger::info("Create socket");
    h_client_socket = socket_creator(domain, type, protocol);
}

void* client::on_recieve(void* data){
    int h_socket = *((int*) data);

    // TODO: rewrite as dynamic recieving function
    char* buffer = new char[1024];
    while(true){
        recv_from_server(h_socket, buffer, 1024);
        logger::info(buffer);
    }

    return NULL;
}

void client::connect(){
    logger::info("Create connection to server");
    server_connection.sin_addr.s_addr = inet_addr(server_ip.c_str());
	server_connection.sin_family = domain;
	server_connection.sin_port = htons( port );
    connect_to_server(h_client_socket, (struct sockaddr*) &server_connection, sizeof(server_connection));
}

void client::main(){
    std::string command = "";
    logger::info("Create thread for display answers from server");
    if(pthread_create(&server_answers_thread, NULL, client::on_recieve, &h_client_socket))
        logger::fatal("Failed to create thread for display answers from server");

    logger::info("Waiting for commands");
    while(true){
        std::cout << "client:> ";
        std::cin >> command;
        std::cout << std::endl;

        if(command == "-exit"){
            logger::info("Successfully exit and disconnected");
            break;
        }

        if(command == "-send"){
            std::cout << "Enter message to send -> ";
            std::cin >> command;
            send_to_server(h_client_socket, (char*) command.c_str(), command.size());
            command = "";
        }       
    }
}
////////////////////////////////////////////////////////////////
//                      Setters functions  
////////////////////////////////////////////////////////////////
void client::set_protocol(int protocol){
    this->protocol = protocol;
}

void client::set_domain(int domain){
    this->domain = domain;
}

void client::set_type(int type){
    this->type = type;
}

void client::set_port(int port){
    this->port = port;
}

void client::set_settings(int protocol, int domain, int type, int port){
    this->protocol = protocol;
    this->domain = domain;
    this->type = type;
    this->port = port;
}

void client::set_address(const std::string& address){
    this->server_ip = address;
}
////////////////////////////////////////////////////////////////
//                      Public functions  
////////////////////////////////////////////////////////////////
void client::start(){
    logger::info("Start client");
    create_socket();
    connect();
    main();
}

void client::stop(){
    // Close the socket
    if(h_client_socket != 0){
        close(h_client_socket);
        h_client_socket = 0;
    }

    // Hard close thread
    // TODO: Need to create thread pool
    if(server_answers_thread != 0){
        pthread_cancel(server_answers_thread);
        server_answers_thread = 0; 
    }
}