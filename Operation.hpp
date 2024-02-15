#ifndef  OPERATION_HPP
#define OPERATION_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <unordered_map>
#include "DataType.hpp"

using namespace std;

class operation
{
    
    
    public:
    vector <int > tax;
    vector <int > sub;
    vector <int > bus;
    void read_dis(string, ifstream &, unordered_map<string , int> &, DataType [59][59] );
    void read_cost(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void read_cost_line(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void setItems_dis(unordered_map<string , int> &, DataType[59][59]);
    void setItems_cost(unordered_map<string , int> &, DataType[59][59]);
    int getIndex (unordered_map<string , int> , string);
};
#endif