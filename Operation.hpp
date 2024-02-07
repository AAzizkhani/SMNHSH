#ifndef  OPERATION_HPP
#define OPERATION_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <unordered_map>
#include "DataType.hpp"

using namespace std;

class operation
{
    public:
    void setItems(unordered_map<string , int> &, DataType[59][59]);
    int getIndex (unordered_map<string , int> , string);
};
#endif