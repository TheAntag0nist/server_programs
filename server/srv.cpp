#include "srv.h"
////////////////////////////////////////////////////////////////
//                      On init server
////////////////////////////////////////////////////////////////
server::server(){
    protocol = 0;
    domain = 0;
    type  = 0;
    port = 0;

    h_server_socket = 0;
    server_addr = {0};
}
////////////////////////////////////////////////////////////////
//                      On destroy server
////////////////////////////////////////////////////////////////
server::~server(){
    if(h_server_socket != 0)
        close(h_server_socket);
}
////////////////////////////////////////////////////////////////
//                      Private functions    
////////////////////////////////////////////////////////////////
void server::create_socket(){
    logger::info("Create server socket");
    h_server_socket = socket_creator(IPv4, TCP, 0);
}

void server::bind(){

}

void server::listen(){

}

void server::accept(){

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
    
}