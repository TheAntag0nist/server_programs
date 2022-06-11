#ifndef APPSETTINGS_H
#define APPSETTINGS_H
#include "interface_config.h"
#include "log_config.h"
#include "srv_config.h"
#include "app_config.h"

class config_data : i_config{
public:
    logger_config log_config_data;
    server_config srv_config_data;
    app_config app_config_data;

    // TODO: Upgrade reading configuration file to dynamic format
    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

std::string config_data::get_info(){
    std::stringstream ss;
    ss << log_config_data.get_info();
    ss << srv_config_data.get_info();
    ss << app_config_data.get_info();

    return ss.str();
}

void config_data::parse_config(const json& config){
    // application configuration
    app_config_data.parse_config(config);
    // server configuration
    srv_config_data.parse_config(config);
    // logger configuration
    log_config_data.parse_config(config);
}

#endif