#include <Config/config.h>

std::string config_data::get_info(){
    std::stringstream ss;
    ss << log_config_data.get_info();
    ss << app_config_data.get_info();

    if(is_server)
        ss << srv_config_data.get_info();
    else
        ss << client_config_data.get_info();

    return ss.str();
}

void config_data::parse_config(const json& config){
    // application configuration
    app_config_data.parse_config(config);
    // logger configuration
    log_config_data.parse_config(config);

    if(is_server)
        srv_config_data.parse_config(config);
    else
        client_config_data.parse_config(config);
}