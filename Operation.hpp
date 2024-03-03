#ifndef  OPERATION_HPP
#define OPERATION_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <unordered_map>
#include "DataType.hpp"
#include "saveType.hpp"
#include "saveDirect.hpp"
#define V 59

using namespace std;

class operation
{
    
    private:

        vector<string>bline1;
        vector<string>bline2;
        vector<string>bline3;

        vector<string>sline1;
        vector<string>sline2;
        vector<string>sline3;
        vector<string>sline4;

        vector<int>bbline1;
        vector<int>bbline2;
        vector<int>bbline3;

        vector<int>ssline1;
        vector<int>ssline2;
        vector<int>ssline3;
        vector<int>ssline4;
        
        vector<int>ttline1;
        vector<int>ttline2;
        vector<int>ttline3;
        vector<int>ttline4;
        Save_data saveVehicles[V];
        //vector<saveDirect> bus;


         int  z = 0;

    
    public:
     
    void read_dis(string, ifstream &, unordered_map<string , int> &, DataType [59][59] );
    void read_cost_sub( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void read_cost_tax( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59], int);
    void read_cost_bus( vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void read_time(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59], int);
    void read_cost_line(char, vector <int>, ifstream &, unordered_map<string , int> &, DataType [59][59]);
    void setItems_dis(unordered_map<string , int> &, DataType[59][59]);
    void setItems_cost(unordered_map<string , int> &, DataType[59][59], int );
    void setAlltype(unordered_map<string , int> &, DataType[59][59], int, vector<int>, saveDirect [V]);
    void set_bus_line1(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_bus_line2(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_bus_line3(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_sub_line1(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_sub_line2(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_sub_line3(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_sub_line4(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_taxi_line1(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_taxi_line2(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_taxi_line3(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);
    void set_taxi_line4(unordered_map<string , int> & t, DataType station[59][59], int index, vector<int> timeoftype, saveDirect dir[V]);

    vector <int>  setItems_time(unordered_map<string , int> &, DataType[59][59], int);
    int getIndex (unordered_map<string , int> , string);
    string search(int,unordered_map<string , int>);
    vector<string> get_bline1(){return bline1;};
    vector<string> get_bline2(){return bline2;};
    vector<string> get_bline3(){return bline3;};
    vector<string> get_sline1(){return sline1;};
    vector<string> get_sline2(){return sline2;};
    vector<string> get_sline3(){return sline3;};
    vector<string> get_sline4(){return sline4;};

};
#endif