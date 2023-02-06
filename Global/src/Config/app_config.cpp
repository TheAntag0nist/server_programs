#include <Config/app_config.h>

std::string app_config::get_info(){
    std::stringstream ss;
    ss << "Application configuration: \n";
    ss << "\tCode Name: " << code_name << std::endl;
    ss << "\tApp Name: " << app_name << std::endl;
    ss << "\tVersion: " << version << std::endl;

    return ss.str();
}

void app_config::parse_config(const json& config){
    // application configuration
    app_name = config["app_config"]["app_name"].get<std::string>();
    code_name = config["app_config"]["code_name"].get<std::string>();
    version = config["app_config"]["version"].get<std::string>();
}