#include <Config/log_config.h>

std::string logger_config::get_info(){
    std::stringstream ss;
    ss << "Logging configuration: \n";
    ss << "\tlog_file: " << log_file << std::endl;

    return ss.str();
}

void logger_config::parse_config(const json& config){
    log_file = config["logger_config"]["log_file"].get<std::string>();
}