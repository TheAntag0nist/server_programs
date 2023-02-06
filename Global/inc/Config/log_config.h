#ifndef LOG_CONFIG_H
#define LOG_CONFIG_H
#include "interface_config.h"

class logger_config : i_config{
public:
    std::string log_file;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

#endif 