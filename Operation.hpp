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
    
    
    public:;
    void read_dis(string, ifstream &, unordered_map<string , int> &, DataType [59][59] );
    void read_cost_sub( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void read_cost_tax( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59], int);
    void read_cost_bus( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);

    void read_time(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59], int);
    void read_cost_line(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void setItems_dis(unordered_map<string , int> &, DataType[59][59]);
    void setItems_cost(unordered_map<string , int> &, DataType[59][59], int );
    vector <int>  setItems_time(unordered_map<string , int> &, DataType[59][59], int);
    int getIndex (unordered_map<string , int> , string);
};
#endif