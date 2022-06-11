#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

#include "./termcolor.hpp"

enum msg_type{
    NONE,
    INF,
    WRN,
    ERR,
    FTL
};

class logger{
private:
    static std::string log_file_name;
    static std::ofstream log_file;

public:
    static std::string get_current_time();
    static void set_log_file(std::string name_log_file);
    static void close_log_file();
    static void message(const std::string& message, msg_type msg_type = NONE, bool write_to_log = true);

    static void info(const std::string& msg, bool write_to_log = true);
    static void warning(const std::string& msg, bool write_to_log = true);
    static void error(const std::string& msg, bool write_to_log = true);
    static void fatal(const std::string& msg, bool write_to_log = true);
};

class log_file_ex : public std::exception{
private:
    std::string ex_msg;
public: 
    log_file_ex(const std::string& msg) : ex_msg(msg) {}
    virtual const char* what() const noexcept { return ex_msg.c_str(); }
};

#endif