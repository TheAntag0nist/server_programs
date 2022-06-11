#ifndef LOG_CONFIG_H
#define LOG_CONFIG_H
#include "interface_config.h"

class logger_config : i_config{
public:
    std::string log_file;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

std::string logger_config::get_info(){
    std::stringstream ss;
    ss << "Logging configuration: \n";
    ss << "\tlog_file: " << log_file << std::endl;

    return ss.str();
}

void logger_config::parse_config(const json& config){
    log_file = config["logger_config"]["log_file"].get<std::string>();
}

#endif 