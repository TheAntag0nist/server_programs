#ifndef APP_INFO_H
#define APP_INFO_H
#include "interface_config.h"
#include <string>

class app_config : i_config{
public:
    std::string code_name;
    std::string app_name;
    std::string version;

    virtual std::string get_info() override;
    virtual void parse_config(const json& config) override;
};

#endif