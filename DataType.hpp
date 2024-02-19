#ifndef  DATATYPE_H
#define DATATYPE_H

#include <iostream>
#include <vector>
#include <atring>
using namespace std;
class DataType
{

private:
    
    int distance=0;
    int cost=0;
    
    string path{};
    string line{};

    vector <int> times{0};
    vector <string> time_type{};
    vector <string> time_line{};

public:

    void set_dis (int);
    void set_cost(int);
    void set_time(int);

    void set_pathh   (string);
    void set_line    (string);
    void set_timeLine(string);
    void set_timeType(string);

    int get_cost();
    int get_dis ();

    vector<int> get_time();

    vector<string> get_timeLine();
    vector<string> get_timeType();

    string get_path();
    string get_line();

};

#endif