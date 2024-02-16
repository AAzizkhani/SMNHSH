#include "DataType.hpp"
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

    
void DataType ::set_dis(int dis)      {distance=dis;}
void DataType ::set_cost(int cost)    {this->cost=cost;}
void DataType::set_pathh(string path){this->path=path;}
void DataType::set_line(string line){this->line=line;}
void DataType::set_time(int time){times.push_back(time);}
void DataType::set_timeLine(string line){time_line.push_back(line);}
void DataType::set_timeType(string type){time_type.push_back(type);}
int DataType::get_cost()    {return cost;}
int DataType::get_dis()     {return distance;}
vector<int> DataType::get_time()     {return times;}
vector<string> DataType::get_timeLine()     {return time_line;}
vector<string> DataType::get_timeType()     {return time_type;}
string DataType::get_path() {return path;}
string DataType::get_line() {return line;}
