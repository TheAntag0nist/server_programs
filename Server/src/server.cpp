#include <Config/config.h>
#include <json.hpp>
#include <Log/logger.h>
#include <core.h>

#include <iostream>
#include <fstream>

using json = nlohmann::json;
////////////////////////////////////////////////////////////////
//                      Global variables
////////////////////////////////////////////////////////////////
server server_obj;
config_data server_conf;
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
        logger::set_log_file(server_conf.log_config_data.log_file);
        logger::info("Starting server");
        logger::info("Configuration loaded: \n" + server_conf.get_info());

        on_startup();
    }
    catch(const std::exception& ex) {
        logger::error(ex.what());
    }

    on_close();
    logger::info("Close server");
    logger::close_log_file();
    return 0;
}
////////////////////////////////////////////////////////////////
//              Global functions realizations
////////////////////////////////////////////////////////////////
void read_config(){
    // Initial file settings
    const std::string filename = "config.json";
    std::fstream config_file(filename);
    
    if(config_file.is_open()){
        json config = json::parse(config_file);
        logger::info("Reading server configuration\n" + config.dump());
        server_conf.parse_config(config);
    }
    else
        throw std::runtime_error("Can not open config file");

    return;
}

void on_startup(){
    // Fill settings for server
    int domain = get_domain(server_conf.srv_config_data.domain);
    int type = get_type(server_conf.srv_config_data.type);

    server_obj.set_protocol(server_conf.srv_config_data.protocol);
    server_obj.set_domain(domain);
    server_obj.set_port(server_conf.srv_config_data.port);
    server_obj.set_type(type);

    server_obj.set_max_connections(server_conf.srv_config_data.max_connections);
    server_obj.set_address(server_conf.srv_config_data.address);

    // Run server
    server_obj.start();
    return;
}

void on_close(){
    // Close server and connections
    logger::info("Stopping server");
    server_obj.stop();
    return;
}