#include <iostream>
#include <unordered_map>

#define V 59
using namespace std;


#include <iostream>
#include <vector>

using namespace std;

class saveDirect // saveDirect is that class we want to save our route distance and which viechel we use
{
    public:
    int distance {__INT_MAX__};
    vector<string> direct;
    vector<string> type;

};

string search(int inputKey , unordered_map<string , int> inputMap) // searching for stations
{
    for (auto i : inputMap)
    {
        if (i.second == inputKey) return i.first;
    }
}

int minDistance(saveDirect dir[] , bool setSpt[]) 
{
    int min {__INT_MAX__};
    int minIndex;

    for (int ver{0} ; ver < V ; ver++ )//*change
    {
        if (!setSpt[ver] && dir[ver].distance <= min)
        {
            min = dir[ver].distance;
            minIndex = ver;
        }
    }

    return minIndex; 
}

//* change
void dijkstra(int src , int dest , DataType stations[V][V])
{
    if (src >= 0 && src <= V-1 &&
       dest >= 0 && dest<= V-1)
    {
        saveDirect dir[V];
        bool setSpt[V] {false};

        dir[src].distance = 0;
        dir[src].direct.push_back(search(src));

        for (int i{0} ; i < V-1 ; i++)
        {
            string viechel{""};
            int minIndex = minDistance(dir , setSpt);

            setSpt[minIndex] {true};

            for (int j{0} ; j< V ; j++)
            {
                if (!setSpt[j] && stations[minIndex][j].distance && dir[minIndex].distance != __INT_MAX__&&
                    dir[minIndex].distance + stations[minIndex][j].distance < dir[j].distance)
                    {
                        dir[j].distance = dir[j].distance + stations[minIndex][j].distance;

                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].path);
                    }
            }
        }

        cout << dir[dest].distance << "\n";

        for ( int i{0} ; i<dir[dest].direct.size() - 1 ;i++)
        {
            cout << dir[dest].direct[i];

            if ( dir[dest].type[i] == "line1" ||
                 dir[dest].type[i] == "line6" ||
                 dir[dest].type[i] == "line3" ||
                 dir[dest].type[i] == "line4" ||) cout << "Taxi or Subway";

            else cout << "Bus";
        }
        cout << dir[dest].direct[dir[dest].direct.size() - 1];
    }

    else throw invalid_argument("Not exist!");
}

int main()
{
    unordered_map<string ,  int> index;

    data_type stations[V][V];

    operation operatorr;

    operatorr.set_items(index, stations);

}