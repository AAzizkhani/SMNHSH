#ifdef  OPERATION_HPP
#define OPERATION_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <unordered_map>

#include "DataType.hpp"

class operation
{
    public:
    void setItems(unordered_map<string , int> , data_type[][]);
    int getIndex (unordered_map<string , int> , std::string);
};
#endif