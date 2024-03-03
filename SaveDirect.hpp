#ifndef  SAVEDIRECT_H
#define  SAVEDIRECT_H

#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>


#define V 59

using namespace std;
class saveDirect
    {
    public:
    int distance {__INT_MAX__};
    vector<string> direct;
    vector<string> type;
    vector<string> line;
    vector<int> arr_time;
    };

#endif