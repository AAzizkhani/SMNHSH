#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "DataType.hpp"
#include "Operation.hpp"
#include "Dijkstra.hpp"

#define V 59
using namespace std;

int main()
{
    
    try
    {
        vector <int> timeOfType;
        
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
        d.dijkstra(in1 , in2 , stations , index);
        cout<<endl;
        cout<< "Arriving time (ad minute): "<<'\n';
        d.dijkstra_ARtime(in1 , in2 , stations , index );
        cout<<endl;
        cout<<"min cost: "<<'\n';
        operatorr.setItems_cost(index, stations);
        d.dijkstra_cost(in1 , in2 , stations , index);
        cout<<"min time:"<<'\n';
        timeOfType=operatorr.setItems_time(index, stations);
        d.dijkstra_time(in1 , in2 , stations , index, timeOfType);

       

    }

    catch(invalid_argument &e)
    {
        cout << e.what();
    }
}