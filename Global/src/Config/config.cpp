#include <Config/config.h>

std::string config_data::get_info(){
    std::stringstream ss;
    ss << log_config_data.get_info();
    ss << app_config_data.get_info();

#ifdef SERVER_CONFIG
    ss << srv_config_data.get_info();
#elif CLIENT_CONFIG
    ss << client_config_data.get_info();
#endif

    return ss.str();
}

void config_data::parse_config(const json& config){
    // application configuration
    app_config_data.parse_config(config);
    // logger configuration
    log_config_data.parse_config(config);

#ifdef SERVER_CONFIG
    // server configuration
    srv_config_data.parse_config(config);
#elif CLIENT_CONFIG
    // client configuration
    client_config_data.parse_config(config);
#endif
}