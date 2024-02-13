#include <iostream>
#include "Dijkstra.hpp"


using namespace std;


string Dijkstra::search(int inputKey , unordered_map<string , int> inputMap) 
{
    for (auto i : inputMap)
    {
        if (i.second == inputKey) return i.first;
    }
    return 0;
}

int Dijkstra::minDistance(saveDirect dir[] , bool setSpt[]) 
{
    int min {__INT_MAX__};
    int minIndex;

    for (int ver{0} ; ver < V ; ver++ )
    {
        if (!setSpt[ver] && dir[ver].distance <= min)
        {
            min = dir[ver].distance;
            minIndex = ver;
        }
    }

    return minIndex; 
}

void Dijkstra::dijkstra (int src , int dest , DataType stations[V][V], unordered_map<string , int> inputMap )
{
    if (src >= 0 && src <= V-1 &&
       dest >= 0 && dest<= V-1)
    {
        saveDirect dir[V];
        bool setSpt[V] {false};

        dir[src].distance = 0;
        dir[src].direct.push_back(search(src,inputMap));

        for (int i{0} ; i < V-1 ; i++)
        {
            string viechel{""};
            int minIndex = minDistance(dir , setSpt);
            setSpt[minIndex] = true;
            for (int j{0} ; j< V ; j++)
            {
                if (!setSpt[j] && stations[minIndex][j].get_dis() && dir[minIndex].distance != __INT_MAX__&&
                    dir[minIndex].distance + stations[minIndex][j].get_dis() < dir[j].distance)
                    {
                         
                        dir[j].distance = dir[minIndex].distance + stations[minIndex][j].get_dis();
                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].get_path());
                    }
            }

        }

        cout << dir[dest].distance << "\n";

        for ( int i{0} ; i<dir[dest].direct.size() - 1 ;i++)
        {
            cout << dir[dest].direct[i]<<"\t";
            cout<<dir[dest].type[i]<<"\t";
        }
        cout << dir[dest].direct[dir[dest].direct.size() - 1]<<'\n';
        dir->type.clear();
        dir->direct.clear();
    }

    else throw invalid_argument("Not exist!");
}
void Dijkstra::dijkstra_cost (int src , int dest , DataType stations[V][V], unordered_map<string , int> inputMap )
{
    if (src >= 0 && src <= V-1 &&
       dest >= 0 && dest<= V-1)
    {
        saveDirect dir[V];
        bool setSpt[V] {false};

        dir[src].distance = 0;
        dir[src].direct.push_back(search(src,inputMap));

        for (int i{0} ; i < V-1 ; i++)
        {
            string viechel{""};
            int minIndex = minDistance(dir , setSpt);
            setSpt[minIndex] = true;
            for (int j{0} ; j< V ; j++)
            {
                if (!setSpt[j] && stations[minIndex][j].get_dis() && dir[minIndex].distance != __INT_MAX__)
                    {                       

                        if(dir[j].line.size()==0 ||( stations[minIndex][j].get_line() != dir[j].line[dir[j].line.size()-1]
                        && dir[minIndex].distance + stations[minIndex][j].get_dis() < dir[j].distance) || dir[j].type[dir[j].type.size()-1]=="taxi")//وارد حلقه های شرظ نمیشه
                        {
                        dir[j].distance = dir[minIndex].distance + stations[minIndex][j].get_dis();
                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].get_path());  
                        } 

                        if(dir[j].line.size()>0 && stations[minIndex][j].get_line() == dir[j].line[dir[j].line.size()-1]
                        && dir[minIndex].distance < dir[j].distance)
                        {

                        dir[j].distance = dir[minIndex].distance;
                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].get_path());   

                        }     
                    }
            }

        }

        cout << dir[dest].distance << "\n";

        for ( int i{0} ; i<dir[dest].direct.size() - 1 ;i++)
        {
            cout << dir[dest].direct[i]<<"\t";
            cout<<dir[dest].type[i]<<"\t";
        }
        cout << dir[dest].direct[dir[dest].direct.size() - 1]<<'\n';
        dir->type.clear();
        dir->direct.clear();
        dir->line.clear();
    }

    else throw invalid_argument("Not exist!");
}
