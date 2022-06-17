#include "package.h"
////////////////////////////////////////////////////////////////////////
//                          Package Construct and Destruct
////////////////////////////////////////////////////////////////////////
package::package(){
    package_data = nullptr;
    package_cnt = 0;
}

package::package(const std::string data){
    this->set_package_data(data);
}

package::~package(){
    clear_package();
}
////////////////////////////////////////////////////////////////////////
//                          Package Functions
////////////////////////////////////////////////////////////////////////
bool package::is_empty() const{
    if(package_data == nullptr && package_cnt == 0)
        return true;
    
    if(package_data == nullptr && package_cnt != 0)
        throw std::runtime_error("package::is_empty null package data, but package counter not null");
    if(package_data != nullptr && package_cnt == 0)
        throw std::runtime_error("package::is_empty null counter, but package data not null");
    
    return false;
}

int package::clear_package(){
    if(!is_empty()){
        delete[] package_data;
        package_data = nullptr;
        package_cnt = 0;
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////
//                          Package Getters
////////////////////////////////////////////////////////////////////////
int package::get_package_cnt() const{
    return this->package_cnt;
}

std::string package::get_package_data() const{
    std::string result = "";
    if(!this->is_empty())
        for(int i = 0; i < this->package_cnt; ++i)
            result += this->package_data[i];
    
    return result;
}

std::string package::get_package_data(int id) const{
    if(!is_empty())
        if(id >= 0 && id < package_cnt)
            return this->package_data[id];

    return "";
}
////////////////////////////////////////////////////////////////////////
//                          Package Setters
////////////////////////////////////////////////////////////////////////
void package::set_package_data(const std::string data){
    if(!is_empty())
        clear_package();

    if(data == "")
        throw std::invalid_argument("invalid package -> data is empty");

    if(data.size() > PACKAGE_MAX_SIZE)
        package_cnt = std::ceil(data.size() / PACKAGE_MAX_SIZE);
    else
        package_cnt = 1;

    package_data = new std::string[package_cnt];
    // save package_data
    int data_size = data.size();
    int current_pos = 0;
    for(int i = 0; i < package_cnt; ++i){
        int next_pos = (current_pos + PACKAGE_MAX_SIZE - data_size) < 0 ? data_size - current_pos : current_pos + PACKAGE_MAX_SIZE;
        package_data[i] = data.substr(current_pos, next_pos);
        current_pos += package_data[i].size();
    }
}
////////////////////////////////////////////////////////////////////////
//                          Package Overloads
////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream &out, package& package_obj){
    out << package_obj.get_package_data();
    return out;
}

std::istream& operator>>(std::istream &in, package& package_obj){
    std::string input_data;
    // clear cin stream
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    // read data
    std::getline(std::cin, input_data);
    package_obj.set_package_data(input_data);
    return in;
}