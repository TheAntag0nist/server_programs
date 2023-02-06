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

    std::string address;
    int max_connections;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

#endif