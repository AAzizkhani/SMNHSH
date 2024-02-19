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

        for ( size_t i{0} ; i<dir[dest].direct.size() - 1 ;i++)
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
                if (!setSpt[j] && stations[minIndex][j].get_cost() && dir[minIndex].distance != __INT_MAX__)
                    {                       

                        if(dir[minIndex].line.size()==0 || ( stations[minIndex][j].get_line() != dir[minIndex].line[dir[minIndex].line.size()-1]
                        && dir[minIndex].distance + stations[minIndex][j].get_dis() < dir[j].distance)
                        || stations[j][minIndex].get_path()=="taxi")
                        {
                        
                        dir[j].distance = dir[minIndex].distance + stations[minIndex][j].get_cost();

                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].get_path());

                        dir[j].line = dir[minIndex].line;
                        dir[j].line.push_back(stations[j][minIndex].get_line()); 
                      //  cout<<stations[minIndex][j].get_line()<<"  "<<dir[j].line[dir[j].line.size()-1]<<endl;
                        } 

                        else if(dir[minIndex].line.size()==0 || stations[minIndex][j].get_line() == dir[minIndex].line[dir[minIndex].line.size()-1]
                        && dir[minIndex].distance < dir[j].distance)
                        {
                        dir[j].distance = dir[minIndex].distance;

                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(stations[j][minIndex].get_path());

                        dir[j].line = dir[minIndex].line;
                        dir[j].line.push_back(stations[j][minIndex].get_line());

                        }     
                    }
            }

        }

        cout << dir[dest].distance << "\n";
        for ( size_t i{0} ; i<dir[dest].direct.size() - 1 ;i++)
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
void Dijkstra::dijkstra_time (int src , int dest , DataType stations[V][V], unordered_map<string , int> inputMap, vector <int> timeOfType )
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

                vector <int> temptime=stations[minIndex][j].get_time();
                if (!setSpt[j] && temptime.size()>0 && dir[minIndex].distance != __INT_MAX__)
                    {
                       // cout<<"ya?";
                        vector <string> templine= stations[minIndex][j].get_timeLine();
                        vector <string> temptype= stations[minIndex][j].get_timeType();
                        string temp_line, temp_type;
                        for(auto i : temptime)
                        {
                            //cout<<"ha";
                            if(dir[minIndex].type.size()==0 || temptype[i] != dir[minIndex].type[dir[minIndex].type.size()-1])
                            {
                               
                                //cout<<templine[i].size(); cout<<"yan";
                                if(temptype[i]=="bus")
                                {
                                    //cout<<"wob";
                                    if(dir[minIndex].distance + temptime[i] + timeOfType[5] < dir[j].distance)
                                    {
                                        //cout<<"jn";
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        //cout<<"jn2";
                                        temp_line=templine[i];
                                        //cout<<"jn3";
                                        temp_type=temptype[i];
                                    }
                                }
                               
                                if(temptype[i]=="subway")
                                {

                                    if(dir[minIndex].distance + temptime[i] + timeOfType[3] < dir[j].distance)
                                    {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                    }
                                }
                                if(temptype[i]=="taxi")
                                {

                                    if(dir[minIndex].distance + temptime[i] + timeOfType[4] < dir[j].distance)
                                    {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                    }
                                }

                            }
                            if(dir[minIndex].type.size()>0 && temptype[i] == dir[minIndex].type[dir[minIndex].type.size()-1])
                            {
                                if(dir[minIndex].line.size()==0 ||templine[i]!=dir[minIndex].line[dir[minIndex].line.size()-1])
                                {
                                    if(temptype[i]=="bus")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[5] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }
                                    if(temptype[i]=="subway")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[3] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }
                                    if(temptype[i]=="taxi")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[4] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }
                                }
                                if(dir[minIndex].line.size()>0 && templine[i]==dir[minIndex].line[dir[minIndex].line.size()-1])
                                {
                                    if(temptype[i]=="bus")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[5] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }
                                    if(temptype[i]=="subway")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[3] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }
                                    if(temptype[i]=="taxi")
                                    {
                                        if(dir[minIndex].distance + temptime[i] + timeOfType[4] < dir[j].distance)
                                        {
                                        dir[j].distance = dir[minIndex].distance + temptime[i];
                                        temp_line=templine[i];
                                        temp_type=temptype[i];
                                        }
                                    }    
                                }
                                
                            }
                        
                        }
                        dir[j].direct = dir[minIndex].direct;
                        dir[j].direct.push_back(search(j,inputMap));

                        dir[j].type = dir[minIndex].type;
                        dir[j].type.push_back(temp_type);

                        dir[j].line = dir[minIndex].line;
                        dir[j].line.push_back(temp_line);
                        
      
                        
                    }
            }

        }

        int tut_time=0;
        for ( size_t i{0} ; i<dir[dest].direct.size() - 1 ;i++)
        {
            cout << dir[dest].direct[i]<<"\t";
            cout<<dir[dest].type[i]<<"\t";
            cout<<dir[dest].arr_time[i]<<"\t";
            tut_time+=dir[dest].arr_time[i];

        }
        cout << dir[dest].direct[dir[dest].direct.size() - 1]<<'\n'<<"total: ";
        cout<<tut_time<<'\n';
        dir->type.clear();
        dir->direct.clear();
        dir->arr_time.clear();
    }

    else throw invalid_argument("Not exist!");
}
void Dijkstra::dijkstra_ARtime (int src , int dest , DataType stations[V][V], unordered_map<string , int> inputMap)
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

                        dir[j].line = dir[minIndex].line;
                        dir[j].line.push_back(stations[j][minIndex].get_line());

                        if(dir[minIndex].line.size()==0 || stations[minIndex][j].get_line() != dir[minIndex].line[dir[minIndex].line.size()-1])
                        {
                            if(dir[j].type.size()>0 && dir[j].type[dir[j].type.size()-1]=="bus")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()*4 + 15);   
                            }
                            if(dir[j].type.size()>0 && dir[j].type[dir[j].type.size()-1]=="subway")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis() + 8);  
                            }
                            if(dir[j].type.size()>0 && dir[j].type[dir[j].type.size()-1]=="taxi")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()*2 + 5);  
                            }
                        }

                        if(dir[minIndex].line.size()>0 && stations[minIndex][j].get_line() == dir[minIndex].line[dir[minIndex].line.size()-1])
                        {
                            if(dir[minIndex].type[dir[minIndex].type.size()-1] == stations[j][minIndex].get_path() && dir[j].type[dir[j].type.size()-1]=="bus")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()*4);   
                            }
                            else if(dir[minIndex].type[dir[minIndex].type.size()-1] != stations[j][minIndex].get_path() && dir[j].type[dir[j].type.size()-1]=="bus")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back((stations[minIndex][j].get_dis()*4)+ 15); 
                            }
                            if(dir[minIndex].type[dir[minIndex].type.size()-1] == stations[j][minIndex].get_path() && dir[j].type[dir[j].type.size()-1]=="subway")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis());  
                            }
                            else if(dir[minIndex].type[dir[minIndex].type.size()-1] != stations[j][minIndex].get_path() &&dir[j].type[dir[j].type.size()-1]=="subway")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()+8);  
                            }
                            if(dir[minIndex].type[dir[minIndex].type.size()-1] == stations[j][minIndex].get_path() && dir[j].type[dir[j].type.size()-1]=="taxi")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()*2);  
                            }
                            else if(dir[minIndex].type[dir[minIndex].type.size()-1] != stations[j][minIndex].get_path() && dir[j].type[dir[j].type.size()-1]=="taxi")
                            {
                                dir[j].arr_time=dir[minIndex].arr_time;
                                dir[j].arr_time.push_back(stations[minIndex][j].get_dis()*2 + 5);
                            }
                           
                        }
                        
                    }
            }

        }

        int tut_time=0;
        for ( size_t i{0} ; i<dir[dest].direct.size() - 1 ;i++)
        {
            cout << dir[dest].direct[i]<<"\t";
            cout<<dir[dest].type[i]<<"\t";
            cout<<dir[dest].arr_time[i]<<"\t";
            tut_time+=dir[dest].arr_time[i];

        }
        cout << dir[dest].direct[dir[dest].direct.size() - 1]<<'\n'<<"total: ";
        cout<<tut_time<<'\n';
        dir->type.clear();
        dir->direct.clear();
        dir->arr_time.clear();
    }

    else throw invalid_argument("Not exist!");
}

