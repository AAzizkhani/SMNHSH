#include "saveType.hpp"
#include <iostream>
#include <string>


using namespace std;


    void saveType :: set_type(string vehiclee){vehicle.push_back(vehiclee);}
    void saveType::set_line(string vehicle_linee){vehicle_line.push_back(vehicle_linee);}
    void saveType:: set_name(string neme){ station_name=name;}
    vector<string> saveType::get_type(){return vehicle;}
    vector<string> saveType::get_line(){return vehicle_line;}
    string saveType::get_name(){return station_name;}

