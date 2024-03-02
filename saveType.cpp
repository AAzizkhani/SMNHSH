#include "saveType.hpp"
#include <iostream>
#include <string>


using namespace std;


    void Save_data :: set_type(string vehiclee){vehicle.push_back(vehiclee);}
    void Save_data::set_line(string vehicle_linee){vehicle_line.push_back(vehicle_linee);}
    void Save_data:: set_name(string name){ station_name=name;}
    vector<string> Save_data::get_type(){return vehicle;}
    vector<string> Save_data::get_line(){return vehicle_line;}
    string Save_data::get_name(){return station_name;}

