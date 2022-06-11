#include "./logger.h"

std::string logger::log_file_name = "";
std::ofstream logger::log_file;

std::string logger::get_current_time(){
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    auto str = oss.str();

    return str;
}

void logger::set_log_file(std::string name_log_file){
    if(log_file.is_open())
        log_file.close();

    log_file_name = name_log_file;
    log_file.open(log_file_name, std::ios::app);
    if(!log_file.is_open())
        throw log_file_ex("Can not open log file");
}

void logger::close_log_file(){
    if(log_file.is_open())
        log_file.close();
}

void logger::message(const std::string& message, msg_type msg_type, bool write_to_log){
    if(!log_file.is_open())
        write_to_log = false;

    switch (msg_type) {
    case NONE:
        std::cout << termcolor::white << "[ " << get_current_time() << " ]\t" << message;
        if(write_to_log) 
            log_file << "[ " << get_current_time() << " ]\t" << message;
        break;
    case INF:
        std::cout << termcolor::green << "[ INF " << get_current_time() << " ]\t" << termcolor::white << message;
        if(write_to_log)
            log_file << "[ INF " << get_current_time() << " ]\t" << message;
        break;
    case WRN:
        std::cout << termcolor::yellow << "[ WRN " << get_current_time() << " ]\t" << termcolor::white << message;
        if(write_to_log)
            log_file << "[ WRN " << get_current_time() << " ]\t" << message;
        break;
    case ERR:
        std::cout << termcolor::red << "[ ERR " << get_current_time() << " ]\t" << termcolor::white << message;
        if(write_to_log)
            log_file << "[ ERR " << get_current_time() << " ]\t" << message;
        break;
    case FTL:
        std::cout << termcolor::red << "[ FTL " << get_current_time() << " ]\t" << message << termcolor::white << std::endl;
        if(write_to_log)
            log_file << "[ FTL " << get_current_time() << " ]\t" << message << std::endl;
        exit(1);
        break;
    }

    std::cout << std::endl;
    if(write_to_log)
        log_file << std::endl;

    log_file.flush();
}

void logger::info(const std::string& msg, bool write_to_log){
    message(msg, INF, write_to_log);
}

void logger::warning(const std::string& msg, bool write_to_log){
    message(msg, WRN, write_to_log);
}

void logger::error(const std::string& msg, bool write_to_log){
    message(msg, ERR, write_to_log);
}

void logger::fatal(const std::string& msg, bool write_to_log){
    message(msg, FTL, write_to_log);
}