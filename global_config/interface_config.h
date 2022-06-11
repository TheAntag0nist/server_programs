#ifndef INTERFACE_CONFIG_H
#define INTERFACE_CONFIG_H
#include "../nlohmann/json.hpp"
#include "sstream"
#include <string>

using json = nlohmann::json;

class i_config{
public:
    virtual std::string get_info() = 0;
    virtual void parse_config(const json& config) = 0;
};

#endif