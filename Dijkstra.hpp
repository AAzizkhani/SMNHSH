#ifndef  DIJKSTRA_H
#define  DIJKSTRA_H

#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>
#include "DataType.hpp"
#include "Operation.hpp"
#include "saveDirect.hpp"

#define V 59

using namespace std;

class Dijkstra
{
private:
    saveDirect dir[V];
    string search(int,unordered_map<string , int>);
    int minDistance(saveDirect[] , bool[]);

public:
    void dijkstra        (int, int, DataType[V][V], unordered_map<string , int>);
    void dijkstra_cost   (int, int, DataType[V][V], unordered_map<string , int>, operation );
    void dijkstra_ARtime (int, int, DataType[V][V], unordered_map<string , int>);
    void dijkstra_time   (int, int,unordered_map<string , int>, vector <int>, int,  operation&, DataType[V][V] );
    void dijkstra_time1 (int src , int dest , DataType stations[V][V], unordered_map<string , int> inputMap, vector <int> timeOfType,int hour);

    
};

#endif