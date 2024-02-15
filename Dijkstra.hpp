#ifndef  DIJKSTRA_H
#define  DIJKSTRA_H

#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>
#include "DataType.hpp"

#define V 59

using namespace std;

class Dijkstra
{
private:
    class saveDirect
    {
    public:
    int distance {__INT_MAX__};
    vector<string> direct;
    vector<string> type;
    vector<string> line;
    vector<int> arr_time;
    };

    string search(int,unordered_map<string , int>);
    int minDistance(saveDirect[] , bool[]);

public:
    void dijkstra (int, int, DataType[V][V], unordered_map<string , int> );
    void dijkstra_cost (int, int, DataType[V][V], unordered_map<string , int>);
    void dijkstra_time (int, int, DataType[V][V], unordered_map<string , int>);

};

#endif