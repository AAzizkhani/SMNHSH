#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "DataType.hpp"
#include "Operation.hpp"
#include "Dijkstra.hpp"

#define V 59
using namespace std;

int main()
{
    try
    {
        unordered_map<string ,  int> index;

        DataType stations[V][V];

        operation operatorr;

        operatorr.setItems_dis(index, stations);

        string st1,st2;

        getline(cin,st1);
        getline(cin,st2);

        int in1,in2;
        in1=operatorr.getIndex(index,st1);
        in2=operatorr.getIndex(index,st2);
        cout<<"min distance: "<<'\n';
        Dijkstra d;
        d.dijkstra(in1 , in2 , stations , index, false);
        cout<<endl;
        operatorr.setItems_cost(index, stations);
        d.dijkstra(in1 , in2 , stations , index, true);

    }

    catch(invalid_argument &e)
    {
        cout << e.what();
    }
    

}