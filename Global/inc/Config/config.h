#ifndef APPSETTINGS_H
#define APPSETTINGS_H
#include "interface_config.h"
#include "log_config.h"
#include "srv_config.h"
#include "client_config.h"
#include "app_config.h"

class config_data : i_config{
public:
    logger_config log_config_data;
    app_config app_config_data;
    bool is_server = false;

    server_config srv_config_data;
    client_config client_config_data;

    // TODO: Upgrade reading configuration file to dynamic format
    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

#endif