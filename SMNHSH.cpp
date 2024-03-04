#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>

#include "DataType.hpp"
#include "Operation.hpp"
#include "Dijkstra.hpp"

#define V 59
using namespace std;

void readTestCase(string& st1 , string& st2 , string& startHour , string& startMin)
{
    ifstream input;
    input.open("send_testCases.txt");

    getline(input ,startHour, '*');
    getline(input ,startMin, '*');

    getline(input ,st1, '*');
    getline(input, st2);
}

int main()
{
    
    try
    {
        vector <int> timeOfType;
        
        unordered_map<string ,  int> index;
        DataType stations[V][V];
        operation operatorr;

        operatorr.setItems_dis(index, stations);

        string st1,st2, start_min, start_hour;

        //readTestCase(st1 , st2 , start_hour , start_min);
        getline(cin,  st1);
        getline(cin, st2);
        int in1,in2, min=0, hour=2;
        in1=operatorr.getIndex(index,st1);
        in2=operatorr.getIndex(index,st2);
        //min=stoi(start_min);
        //hour= stoi(start_hour);
        cout<<"min distance: "<<'\n';
        Dijkstra d;
        d.dijkstra(in1 , in2 , stations , index);
        cout<<endl;
        cout<< "Arriving time (ad minute): "<<'\n';
        d.dijkstra_ARtime(in1 , in2 , stations , index );
        cout<<endl;
        cout<<"min cost: "<<'\n';
        operatorr.setItems_cost(index, stations, hour);
        d.dijkstra_cost(in1 , in2 , stations , index, operatorr);
        cout<<"min time:"<<'\n';
        timeOfType=operatorr.setItems_time(index, stations, hour);
        d.dijkstra_time(in1 , in2 , stations , index, timeOfType, hour, operatorr);

    }

    catch(invalid_argument &e)
    {
        cout << e.what();
    }
}