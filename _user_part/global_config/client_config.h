#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H
#include "../../interface_config.h"
#include <string>

class client_config : i_config{
public:
    std::string access_token;
    std::string username;

    std::string domain;
    std::string type;
    int protocol;

    std::string server_ip;
    int port;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

std::string client_config::get_info(){
    std::stringstream ss;
    ss << "Client configuration: \n";
    ss << "\tAccess Token: " << access_token << std::endl;
    ss << "\tUserName: " << username << std::endl;
    ss << "\tserver IP: " << server_ip << std::endl;
    ss << "\tPort: " << port << std::endl;

    return ss.str();
}

void client_config::parse_config(const json& config){
    // application configuration
    access_token = config["client_config"]["access_token"].get<std::string>();
    username = config["client_config"]["username"].get<std::string>();

    protocol = config["client_config"]["protocol"].get<int>();
    domain = config["client_config"]["domain"].get<std::string>();
    type = config["client_config"]["type"].get<std::string>();

    server_ip = config["client_config"]["server_ip"].get<std::string>();
    port = config["client_config"]["port"].get<int>();
}

#endif