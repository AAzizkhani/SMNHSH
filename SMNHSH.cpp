// dijkstra is not done yet!
#include <iostream>
#include <unordered_map>

#define V 59
using namespace std;


#include <iostream>
#include <vector>

using namespace std;

class saveDirect
{
    public:
    int distance {0};
    vector<string> direct;
    vector<string> type;

};

int minDistance(saveDirect dir[] , bool setSpt[]) // saveDirect is that class we want to save our route distance and which viechel we use
{
    int min {__INT_MAX__};
    int minIndex;

    for (int ver{0} ; ver < 61 ; ver++ )//*change
    {
        if (!setSpt[ver] && dir[ver].distance <= min)
        {
            min = dir[ver].distance;
            minIndex = ver;
        }
    }

    return minIndex; 
}

void dijkstra(int src , int dest)
{
    //*change
    if (src >= 0 && src <= 61 &&
       dest >= 0 && dest<= 61)
    {
        saveDirect dir[61]; //*change
        bool setSpt[61]; //*change

        dir[src].distance = 0;
        dir[src].distance = 0;


    }
}

int main()
{
    unordered_map<string ,  int> index;

    data_type stations[V][V];

    operation operatorr;

    operatorr.set_items(index, stations);

    

}