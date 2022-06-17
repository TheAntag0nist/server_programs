#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

// 64 Kb
#define PACKAGE_MAX_SIZE 64 * 1024

class package{
private:
    std::string* package_data;
    int package_cnt;

public:
    package();
    package(const std::string);
    ~package();

    // empty checker
    bool is_empty() const;
    // clear package 
    int clear_package();

    // getters
    int get_package_cnt() const;
    std::string get_package_data() const;
    std::string get_package_data(int id) const;

    // setters
    void set_package_data(const std::string);

    // overload for streams
    friend std::ostream& operator<<(std::ostream &out, package& package);
    friend std::istream& operator>>(std::istream &in, package& package);
};

std::ostream& operator<<(std::ostream &out, package& package);
std::istream& operator>>(std::istream &in, package& package);

#endif