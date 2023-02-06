#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H
#include "interface_config.h"
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

#endif