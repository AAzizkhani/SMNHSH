#include "DataType.hpp"
#include <unordered_map>
#include <iostream>

using namespace std;

    
void DataType ::set_dis(int dis)      {distance=dis;}
void DataType ::set_cost(int cost)    {this->cost=cost;}
void DataType::set_pathh(string path){this->path=path;}

int DataType::get_cost()    {return cost;}
int DataType::get_dis()     {return distance;}
string DataType::get_path() {return path;}