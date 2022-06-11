#ifndef SRV_CONFIG_H
#define SRV_CONFIG_H
#include "interface_config.h"
#include <string>

class server_config : i_config{
public:
    std::string domain;
    std::string type;
    int protocol;
    int port;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

std::string server_config::get_info(){
    std::stringstream ss;
    ss << "Server configuration: \n";
    ss << "\tProtocol: " << protocol << std::endl;
    ss << "\tDomain: " << domain << std::endl;
    ss << "\tType: " << type << std::endl;
    ss << "\tPort: " << port << std::endl;

    return ss.str();
}

void server_config::parse_config(const json& config){
    // server configuration
    domain = config["server_config"]["domain"].get<std::string>();
    type = config["server_config"]["type"].get<std::string>();
    protocol = config["server_config"]["protocol"].get<int>();
    port = config["server_config"]["port"].get<int>();\
}

#endif