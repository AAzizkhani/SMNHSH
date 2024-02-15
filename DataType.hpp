#ifndef  DATATYPE_H
#define DATATYPE_H

#include <iostream>
#include <vector>
using namespace std;
class DataType
{

private:
    int distance=0;
    int cost=0;
    string path;
    string line;

public:
    void set_dis(int);
    void set_cost(int);
    void set_pathh(string);
    void set_line(string);
    int get_cost();
    int get_dis();
    string get_path();
    string get_line();

};

#endif