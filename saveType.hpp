#ifndef  saveType_HPP
#define  saveType_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Save_data
{  
    private:
    string station_name;
    vector<string> vehicle;
    vector<string> vehicle_line;
    public:
    void set_type(string vehicle);
    void set_line(string vehicle_line);
    void set_name(string neme);
    string get_name();
    vector<string> get_type();
    vector<string> get_line();

};
#endif