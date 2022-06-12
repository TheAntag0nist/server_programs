#include "global_config/config.h"
#include "../nlohmann/json.hpp"
#include "../log/logger.h"
#include "client/clnt.h"

#include <iostream>
#include <fstream>

using json = nlohmann::json;
////////////////////////////////////////////////////////////////
//                      Global variables
////////////////////////////////////////////////////////////////
client client_obj;
config_data client_conf;
////////////////////////////////////////////////////////////////
//                      Global functions
////////////////////////////////////////////////////////////////
void read_config();
void on_startup();
void on_close();
////////////////////////////////////////////////////////////////
//                      Main function
////////////////////////////////////////////////////////////////
int main(){
    try {
        // Read configuration file
        read_config();
        // Setting for logging
        logger::set_log_file(client_conf.log_config_data.log_file);
        logger::info("Starting client");
        logger::info("Configuration loaded: \n" + client_conf.get_info());

        on_startup();
    }
    catch(const std::exception& ex) {
        logger::error(ex.what());
    }

    on_close();
    logger::info("Close client");
    logger::close_log_file();
    return 0;
}
////////////////////////////////////////////////////////////////
//              Global functions realizations
////////////////////////////////////////////////////////////////
void read_config(){
    // Initial file settings
    const std::string filename = "client_config.json";
    std::fstream config_file(filename);
    
    if(config_file.is_open()){
        json config = json::parse(config_file);
        logger::info("Reading client configuration\n" + config.dump());
        client_conf.parse_config(config);
    }
    else
        throw std::runtime_error("Can not open config file");

    return;
}

void on_startup(){
    // Fill settings for client
    client_obj.set_domain(get_domain(client_conf.client_config_data.domain));
    client_obj.set_type(get_type(client_conf.client_config_data.type));
    client_obj.set_protocol(client_conf.client_config_data.protocol);
    client_obj.set_address(client_conf.client_config_data.server_ip);
    client_obj.set_port(client_conf.client_config_data.port);

    // Run client
    client_obj.start();
    return;
}

void on_close(){
    // Close client and connections
    logger::info("Stopping client");
    client_obj.stop();
    return;
}