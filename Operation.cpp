#include <iostream>
#include <fstream> 
#include <vector>
#include <unordered_map>
#include "Operation.hpp"
//#include "saveType.hpp"
#include <set>
#include <algorithm>
#include <string>
#include "Dijkstra.hpp"

#define V 59
using namespace std;


    void operation::read_cost_tax(  vector <int> costs, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V], int hour )
    {
        string line,dataline1,dataline2,num;
        int dis;
         while (!stfile1.eof()) 
            {
            getline (stfile1, line); //.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            getline (stfile1, num); dis=stoi(num);

                if(hour>17 && hour<21)
                {
                 m[t[dataline1]][t[dataline2]].set_time(costs[3]*dis);
                 m[t[dataline2]][t[dataline1]].set_time(costs[3]*dis);   
                }
                else
                {
                 m[t[dataline1]][t[dataline2]].set_time(costs[0]*dis);
                 m[t[dataline2]][t[dataline1]].set_time(costs[0]*dis);   
                }  
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("taxi");
                m[t[dataline2]][t[dataline1]].set_timeType("taxi");
               

            }

                       
    }
    void operation:: read_cost_bus( vector <int> costs, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V])
    {

        string line,dataline1,dataline2,num;
        int dis;
         while (!stfile1.eof()) 
            {
            getline (stfile1, line); //.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            getline (stfile1, num); //distance
            if(line=="line1")
            {
                if (auto it = find(bline1.begin(), bline1.end(), dataline1)== bline1.end())
                {
                    bline1.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("bus");
                    saveVehicles[t[dataline1]].set_vis(false); 

                }
                if (auto it = find(bline1.begin(), bline1.end(), dataline2)== bline1.end())
                {
                    bline1.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("bus");
                    saveVehicles[t[dataline2]].set_vis(false);

                }
            }
            if(line=="line2")
            {
                if (auto it = find(bline2.begin(), bline2.end(), dataline1)== bline2.end())
                {
                    bline2.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("bus");
                    saveVehicles[t[dataline1]].set_vis(false);

                }
                if (auto it = find(bline2.begin(), bline2.end(), dataline2)== bline2.end())
                {
                    bline2.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("bus");
                    saveVehicles[t[dataline2]].set_vis(false);
                }

            }
            if(line=="line3")
            {
                if (auto it = find(bline3.begin(), bline3.end(), dataline1)== bline3.end())
                {
                    bline3.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("bus");
                    saveVehicles[t[dataline1]].set_vis(false);

                }
                if (auto it = find(bline3.begin(), bline3.end(), dataline2)== bline3.end())
                {
                   bline3.push_back(dataline2);
                   saveVehicles[t[dataline2]].set_line(line);
                   saveVehicles[t[dataline2]].set_type("bus");
                   saveVehicles[t[dataline2]].set_vis(false);
 
                }
            }
        }
        for (int i=0; i<bline1.size(); i++)
        {
            for(int j=0; j<bline1.size(); j++)
            {
                m[t[bline1[i]]][t[bline1[j]]].set_time(costs[2]);
                m[t[bline1[j]]][t[bline1[i]]].set_time(costs[2]);
                 m[t[bline1[i]]][t[bline1[j]]].set_timeLine("line1");
                 m[t[bline1[j]]][t[bline1[i]]].set_timeLine("line1");
                 m[t[bline1[i]]][t[bline1[j]]].set_timeType("bus");
                 m[t[bline1[j]]][t[bline1[i]]].set_timeType("bus");
            }
        }
        for (int i=0; i<bline2.size(); i++)
        {
            for(int j=0; j<bline2.size(); j++)
            {
                m[t[bline2[i]]][t[bline2[j]]].set_time(costs[2]);
                m[t[bline2[j]]][t[bline2[i]]].set_time(costs[2]);
                 m[t[bline2[i]]][t[bline2[j]]].set_timeLine("line2");
                 m[t[bline2[j]]][t[bline2[i]]].set_timeLine("line2");
                 m[t[bline2[i]]][t[bline2[j]]].set_timeType("bus");
                 m[t[bline2[j]]][t[bline2[i]]].set_timeType("bus");
            }
        }
        for (int i=0; i<bline3.size(); i++)
        {
            for(int j=0; j<bline3.size(); j++)
            {
                m[t[bline3[i]]][t[bline3[j]]].set_time(costs[2]);
                m[t[bline3[j]]][t[bline3[i]]].set_time(costs[2]);
                 m[t[bline3[i]]][t[bline3[j]]].set_timeLine("line3");
                 m[t[bline3[j]]][t[bline3[i]]].set_timeLine("line3");
                 m[t[bline3[i]]][t[bline3[j]]].set_timeType("bus");
                 m[t[bline3[j]]][t[bline3[i]]].set_timeType("bus");
            }
        }

    }
    void operation::read_cost_sub(vector <int> costs, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V])
    {

        string line,dataline1,dataline2,num;
        int dis;
         while (!stfile1.eof()) 
            {
            getline (stfile1, line); //.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            getline (stfile1, num); //distance
            if(line=="line1")
            {
                if (auto it = find(sline1.begin(), sline1.end(), dataline1)== sline1.end())
                {
                    sline1.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("subway");
                    saveVehicles[t[dataline1]].set_vis(false); 
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("taxi");
                    saveVehicles[t[dataline1]].set_vis(false);
   
                }
                    
                if (auto it = find(sline1.begin(), sline1.end(), dataline2)== sline1.end())
                {
                    sline1.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("subway");
                    saveVehicles[t[dataline2]].set_vis(false);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("taxi");
                    saveVehicles[t[dataline2]].set_vis(false);

                }

            }
            if(line=="line2")
            {
                if (auto it = find(sline2.begin(), sline2.end(), dataline1)== sline2.end())
                {
                    sline2.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("subway");
                    saveVehicles[t[dataline1]].set_vis(false);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("taxi");
                    saveVehicles[t[dataline1]].set_vis(false);

                }
                if (auto it = find(sline2.begin(), sline2.end(), dataline2)== sline2.end())
                {
                    sline2.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("subway");
                    saveVehicles[t[dataline2]].set_vis(false);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("taxi");
                    saveVehicles[t[dataline2]].set_vis(false);
  

                }

            }
            if(line=="line3")
            {
                if (auto it = find(sline3.begin(), sline3.end(), dataline1)== sline3.end())
                {
                    sline3.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("subway");
                    saveVehicles[t[dataline1]].set_vis(false);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("taxi");
                    saveVehicles[t[dataline1]].set_vis(false);


                }
                if (auto it = find(sline3.begin(), sline3.end(), dataline2)== sline3.end())
                {
                    sline3.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("subway");
                    saveVehicles[t[dataline2]].set_vis(false);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("taxi");
                    saveVehicles[t[dataline2]].set_vis(false);

                }
            }
            if(line=="line4")
            {
                if (auto it = find(sline4.begin(), sline4.end(), dataline1)== sline4.end())
                {
                    sline4.push_back(dataline1);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("subway");
                    saveVehicles[t[dataline1]].set_vis(false);
                    saveVehicles[t[dataline1]].set_line(line);
                    saveVehicles[t[dataline1]].set_type("taxi");
                    saveVehicles[t[dataline1]].set_vis(false);
                }

                if (auto it = find(sline4.begin(), sline4.end(), dataline2)== sline4.end())
                {
                    sline4.push_back(dataline2);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("subway");
                    saveVehicles[t[dataline2]].set_vis(false);
                    saveVehicles[t[dataline2]].set_line(line);
                    saveVehicles[t[dataline2]].set_type("taxi");
                    saveVehicles[t[dataline2]].set_vis(false);


                }
        }
            }
        for (int i=0; i<sline1.size(); i++)
        {
            for(int j=0; j<sline1.size(); j++)
            {
                m[t[sline1[i]]][t[sline1[j]]].set_time(costs[1]);
                m[t[sline1[j]]][t[sline1[i]]].set_time(costs[1]);
                m[t[sline1[i]]][t[sline1[j]]].set_timeLine("line1");
                m[t[sline1[j]]][t[sline1[i]]].set_timeLine("line1");
                m[t[sline1[i]]][t[sline1[j]]].set_timeType("subway");
                m[t[sline1[j]]][t[sline1[i]]].set_timeType("subway");
            }
        }
        for (int i=0; i<sline2.size(); i++)
        {
            for(int j=0; j<sline2.size(); j++)
            {
                m[t[sline2[i]]][t[sline2[j]]].set_time(costs[1]);
                m[t[sline2[j]]][t[sline2[i]]].set_time(costs[1]);
                 m[t[sline2[i]]][t[sline2[j]]].set_timeLine("line2");
                 m[t[sline2[j]]][t[sline2[i]]].set_timeLine("line2");
                 m[t[sline2[i]]][t[sline2[j]]].set_timeType("subway");
                 m[t[sline2[j]]][t[sline2[i]]].set_timeType("subway");
            }
        }
        for (int i=0; i<sline3.size(); i++)
        {
            for(int j=0; j<sline3.size(); j++)
            {
                m[t[sline3[i]]][t[sline3[j]]].set_time(costs[1]);
                m[t[sline3[j]]][t[sline3[i]]].set_time(costs[1]);
                 m[t[sline3[i]]][t[sline3[j]]].set_timeLine("line3");
                 m[t[sline3[j]]][t[sline3[i]]].set_timeLine("line3");
                 m[t[sline3[i]]][t[sline3[j]]].set_timeType("subway");
                 m[t[sline3[j]]][t[sline3[i]]].set_timeType("subway");
            }
        }
        for (int i=0; i<sline4.size(); i++)
        {
            for(int j=0; j<sline4.size(); j++)
            {
                m[t[sline4[i]]][t[sline4[j]]].set_time(costs[1]);
                m[t[sline4[j]]][t[sline4[i]]].set_time(costs[1]);
                m[t[sline4[i]]][t[sline4[j]]].set_timeLine("line4");
                m[t[sline4[j]]][t[sline4[i]]].set_timeLine("line4");
                m[t[sline4[i]]][t[sline4[j]]].set_timeType("subway");
                m[t[sline4[j]]][t[sline4[i]]].set_timeType("subway");
            }
        }
    }
    void operation::read_time( char type, vector <int> timeOfType, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V], int hour )
    {
        string line,dataline1,dataline2,num;
        int dis = 0;
         while (!stfile1.eof()) 
            {
            getline (stfile1, line); //.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            getline (stfile1, num); 
            dis=stoi(num);
            if(type=='b')
            {
                if(hour>5 && hour<9)
                {
                    if(line=="line1")
                    {
                        bbline1.push_back(timeOfType[2]*dis*2);
                    }
                    else if(line=="line2")
                    {
                        bbline2.push_back(timeOfType[2]*dis*2);
                    }
                    else if(line=="line3")
                    {
                        bbline3.push_back(timeOfType[2]*dis*2);
                    }
                    
                    m[t[dataline1]][t[dataline2]].set_time((timeOfType[2]*dis*2));
                    m[t[dataline2]][t[dataline1]].set_time((timeOfType[2]*dis*2));
                }
                else
                {
                    if(line=="line1")
                    {
                        bbline1.push_back(timeOfType[2]*dis);
                    }
                    else if(line=="line2")
                    {
                        bbline2.push_back(timeOfType[2]*dis);
                    }
                    else if(line=="line3")
                    {
                        bbline3.push_back(timeOfType[2]*dis);
                    }
                    m[t[dataline1]][t[dataline2]].set_time((timeOfType[2]*dis));
                    m[t[dataline2]][t[dataline1]].set_time((timeOfType[2]*dis));
                    
                } 
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("bus");
                m[t[dataline2]][t[dataline1]].set_timeType("bus");

            }
            if(type=='s')
            {
                    if(line=="line1")
                    {
                        ssline1.push_back(timeOfType[1]*dis);
                    }
                    else if(line=="line2")
                    {
                        ssline2.push_back(timeOfType[1]*dis);
                    }
                    else if(line=="line3")
                    {
                        ssline3.push_back(timeOfType[1]*dis);
                    }
                    else if(line=="line4")
                    {
                        ssline4.push_back(timeOfType[1]*dis);
                    }
                m[t[dataline1]][t[dataline2]].set_time(timeOfType[1]*dis);
                m[t[dataline2]][t[dataline1]].set_time(timeOfType[1]*dis);
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("subway");
                m[t[dataline2]][t[dataline1]].set_timeType("subway");
            }
            
            if(type=='t')
            {
                if(hour>17 && hour<21)
                {
                    if(line=="line1")
                    {
                        ttline1.push_back(timeOfType[0]*dis*2);
                    }
                    else if(line=="line2")
                    {
                        ttline2.push_back(timeOfType[0]*dis*2);
                    }
                    else if(line=="line3")
                    {
                        ttline3.push_back(timeOfType[0]*dis*2);
                    }
                    else if(line=="line4")
                    {
                        ttline4.push_back(timeOfType[0]*dis*2);
                    }
                    m[t[dataline1]][t[dataline2]].set_time((timeOfType[0]*dis*2));
                    m[t[dataline2]][t[dataline1]].set_time((timeOfType[0]*dis*2));
                }
                else
                {
                    if(line=="line1")
                    {
                        ttline1.push_back(timeOfType[0]*dis);
                    }
                    else if(line=="line2")
                    {
                        ttline2.push_back(timeOfType[0]*dis);
                    }
                    else if(line=="line3")
                    {
                        ttline3.push_back(timeOfType[0]*dis);
                    }
                    else if(line=="line4")
                    {
                        ttline4.push_back(timeOfType[0]*dis);
                    }
                    m[t[dataline1]][t[dataline2]].set_time(timeOfType[0]*dis);
                    m[t[dataline2]][t[dataline1]].set_time(timeOfType[0]*dis);
                }
                
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("taxi");
                m[t[dataline2]][t[dataline1]].set_timeType("taxi");
            }
                       
        }
    }

    void operation::read_dis(string type,ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V] )
    {
        int dis;
        static int j=0;
        string dataline1,dataline2 , num, line;

        while (!stfile1.eof()) 
        {
            getline (stfile1, line); //firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2

            bool flag1=false, flag2=false;
            if (t.find(dataline1)==t.end())
                flag1=true;
                
            if (t.find(dataline2)==t.end())
                flag2=true;
                
            if(flag1)
            {
                t[dataline1]=j;
                saveVehicles[j].set_name(dataline1);
                j++;     
            }
            if(flag2)
            {
                t[dataline2]=j;

                saveVehicles[j].set_name(dataline2);
                j++;     
            }
            getline (stfile1, num);
            dis = stoi(num); 
            if( m[t[dataline1]][t[dataline2]].get_dis()>dis|| m[t[dataline1]][t[dataline2]].get_dis() == 0)
            {
                m[t[dataline1]][t[dataline2]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_pathh(type);
                m[t[dataline1]][t[dataline2]].set_pathh(type);
                m[t[dataline1]][t[dataline2]].set_line(line);
                m[t[dataline2]][t[dataline1]].set_line(line);

            }

        }
    }
void operation::setItems_dis(unordered_map<string , int> &t, DataType m [V][V])
{
    ifstream stfile;
    stfile.open("bus_Routes.txt", ios::in);
    if (stfile.is_open())
    { 
        read_dis("bus", stfile, t, m);
    }  
    stfile.close();

    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
        read_dis("subway", stfile1, t, m);
    } 
    stfile1.close();  
    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
       read_dis("taxi", stfile2, t, m);
    } 
    stfile2.close(); 
}
void operation:: setItems_cost(unordered_map<string , int> &t, DataType m[V][V], int hour)
{
    vector <int> costs;
    ifstream costfile;
    string price;
    int cost;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            m[i][j].set_dis(0);
        }
    }
    costfile.open("price.txt", ios::in);
    if(costfile.is_open())
    {
        while(!costfile.eof())
        {
            getline(costfile, price);//0-> taxi, 1->sub, 2->bus, 3-> traffic(taxi)
            cost=stoi(price);
            costs.push_back(cost);
        }
    }
    costfile.close();
    ifstream stfile;
    stfile.open("bus_Routes.txt", ios::in);

    if (stfile.is_open())
    { 
        read_cost_bus(costs, stfile, t, m);
    }  
    stfile.close();

    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
        read_cost_sub(costs, stfile1, t, m);
    }
    stfile1.close();

    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile2.is_open())
    {
        read_cost_tax(costs, stfile2, t, m, hour);
    }
    stfile2.close();  

}
vector <int> operation:: setItems_time(unordered_map<string , int> &t, DataType m[V][V], int hour)
{
    vector <int> timeOfType;
    string price;
    int cost_time;
    ifstream costfile;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            m[i][j].free_time();
        }
    }
    costfile.open("time_cost.txt", ios::in);
    if(costfile.is_open())
    { 
        while(!costfile.eof())
        {
           
            getline(costfile, price);//0-> taxi, 1->sub, 2->bus, 3-> traffic(taxi)
            cost_time=stoi(price);
            timeOfType.push_back(cost_time);
            
        }
    }
    costfile.close();
    ifstream stfile;
    stfile.open("bus_Routes.txt", ios::in);

    if (stfile.is_open())
    { 
        read_time('b',timeOfType, stfile, t, m, hour);
    }  
    stfile.close();

    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {

        read_time('s',timeOfType, stfile1, t, m, hour);
    }
    stfile1.close();

    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile2.is_open())
    {

        read_time('t',timeOfType, stfile2, t, m, hour);
    }
    stfile2.close();

    return timeOfType;
}
int operation::getIndex(unordered_map<string , int> t,string stn)
{
    if (t.find(stn)==t.end())
        throw invalid_argument("this index does not exist");  
        
    return t[stn];
}
string operation::search(int inputKey , unordered_map<string , int> inputMap) 
{
    for (auto i : inputMap)
    {
        if (i.second == inputKey) return i.first;
    }
    return 0;
}
int operation::find_index(unordered_map<string , int> & t, int index, vector<string>  temp)
{
        for(int k=0; k<V; k++)
        {
            if(temp[index]==search(k, t))
            {
                return k;
            }
        }
        return -1;
}
void operation::setAlltype(unordered_map<string , int> & t, int index, vector<int> timeoftype, saveDirect dir[V], bool visit[V])
{
        vector <string>temptype= saveVehicles[index].get_type();
        vector <string>templine= saveVehicles[index].get_line();
        int temp_ind;
        int count=temptype.size()-1;
        for(int i=0; i<count+1 ; i++)
        { 
            if(temptype[i]=="bus")
            {
                if(templine[i]=="line1" )
                {
                    for(int k=0; k<bline1.size(); k++)
                    {
                        if(bline1[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                   set_bus_line1(t, temp_ind, index, timeoftype, dir, count, i);
                   for(int j=0; j<bline1.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[bline1[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[bline1[j]]].get_type()[q]&&templine[i]== saveVehicles[t[bline1[j]]].get_line()[q])
                            {
                                saveVehicles[t[bline1[j]]].set_true(q);
                            }
                        }
                        
                   }
                }
                if(templine[i]=="line2")
                {
                    for(int k=0; k<bline2.size(); k++)
                    {
                        if(bline2[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                   set_bus_line2(t,temp_ind,index, timeoftype, dir, count, i); 
                   for(int j=0; j<bline2.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[bline2[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[bline2[j]]].get_type()[q]&&templine[i]== saveVehicles[t[bline2[j]]].get_line()[q])
                            {
                                saveVehicles[t[bline2[j]]].set_true(q);
                            }
                        }
                        
                   }
                  
                }
                if(templine[i]=="line3")
                { 
                    for(int k=0; k<bline3.size(); k++)
                    {
                        if(bline3[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }    
                   set_bus_line3(t,temp_ind,index, timeoftype, dir, count, i); 
                  for(int j=0; j<bline3.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[bline3[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[bline3[j]]].get_type()[q]&&templine[i]== saveVehicles[t[bline3[j]]].get_line()[q])
                            {
                                saveVehicles[t[bline3[j]]].set_true(q);
                            }
                        }
                        
                   }
                  
                }
                
            }
            if(temptype[i]=="subway")
            {
                if(templine[i]=="line1")
                {
                    for(int k=0; k<sline1.size(); k++)
                    {
                        if(sline1[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                   set_sub_line1(t,temp_ind,index, timeoftype, dir, count, i);
                 for(int j=0; j<sline1.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline1[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline1[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline1[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline1[j]]].set_true(q);
                            }
                        }
                        
                   }
                 
                }
                if(templine[i]=="line2")
                {
                    for(int k=0; k<sline2.size(); k++)
                    {
                        if(sline2[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_sub_line2(t,temp_ind,index, timeoftype, dir, count, i);
                     for(int j=0; j<sline2.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline2[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline2[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline2[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline2[j]]].set_true(q);
                            }
                        }
                        
                   }
                  
                }
                if(templine[i]=="line3")
                {
                    for(int k=0; k<sline3.size(); k++)
                    {
                        if(sline3[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_sub_line3(t,temp_ind, index,timeoftype, dir, count, i);
                      for(int j=0; j<sline3.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline3[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline3[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline3[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline3[j]]].set_true(q);
                            }
                        }
                        
                   }
                }
                if(templine[i]=="line4")
                {
                    for(int k=0; k<sline4.size(); k++)
                    {
                        if(sline4[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_sub_line4(t,temp_ind, index,timeoftype, dir, count, i);
                      for(int j=0; j<sline4.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline4[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline4[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline4[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline4[j]]].set_true(q);
                            }
                        }
                        
                   }
                    
                }
   
            }
            if(temptype[i]=="taxi")
            {
                if(templine[i]=="line1")
                {
                    for(int k=0; k<sline1.size(); k++)
                    {
                        if(sline1[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_taxi_line1(t, temp_ind,index, timeoftype, dir, count, i);
                     for(int j=0; j<sline1.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline1[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline1[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline1[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline1[j]]].set_true(q);
                            }
                        }
                        
                   }
                }
                if(templine[i]=="line2")
                {
                    for(int k=0; k<sline2.size(); k++)
                    {
                        if(sline2[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_taxi_line2(t, temp_ind, index,timeoftype, dir, count, i);
                       for(int j=0; j<sline2.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline2[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline2[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline2[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline2[j]]].set_true(q);
                            }
                        }
                        
                   }
                }
                if(templine[i]=="line3")
                {
                    for(int k=0; k<sline3.size(); k++)
                    {
                        if(sline3[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_taxi_line3(t,temp_ind,index, timeoftype, dir, count, i);
                        for(int j=0; j<sline3.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline3[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline3[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline3[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline3[j]]].set_true(q);
                            }
                        }
                        
                   }
                }
                if(templine[i]=="line4")
                {
                    for(int k=0; k<sline4.size(); k++)
                    {
                        if(sline4[k]==search(index, t))
                        {
                            temp_ind=k;
                            break;
                        }
                    }
                    set_taxi_line4(t, temp_ind,index, timeoftype, dir,  count, i);
                      for(int j=0; j<sline4.size(); j++)
                   {
                        for(int q=0; q<saveVehicles[t[sline4[j]]].get_type().size(); q++ )
                        {
                            if(temptype[i]==saveVehicles[t[sline4[j]]].get_type()[q]&&templine[i]== saveVehicles[t[sline4[j]]].get_line()[q])
                            {
                                saveVehicles[t[sline4[j]]].set_true(q);
                            }
                        }   
                   }
                }
            }
        }

}
void operation::set_bus_line1(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0 )
        {
            temp_f= find_index(t , index-1, bline1);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
               if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
                {
                if( dir[tem_in].distance + bbline1[index-1] + timeoftype[5]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +bbline1 [index-1] + timeoftype[5];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("bus");
                    dir[temp_f].line.push_back("line1");
                  
                }
                
                } 
            }
            
        }
        if(index<bline1.size()-1)
        {
            temp_f= find_index(t , index+1, bline1);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if( dir[tem_in].line.size()==0 ||dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
                            {
                                if(dir[tem_in].distance + bbline1[index] + timeoftype[5]< dir[temp_f].distance)
                                {
                                    dir[temp_f].distance = dir[tem_in].distance + bbline1[index] + timeoftype[5];
                                    dir[temp_f].direct=dir[tem_in].direct;
                                    dir[temp_f].line=dir[tem_in].line;
                                    dir[temp_f].type=dir[tem_in].type;
                                    dir[temp_f].direct.push_back(search(temp_f, t));
                                    dir[temp_f].type.push_back("bus");
                                    dir[temp_f].line.push_back("line1");
                                  
                                }
                                
                            }
            }
           
        }
        for(int a=index+1; a<bline1.size()-1; a++)
        {
            temp_f= find_index(t , a+1, bline1);
            tem_in= find_index(t , a, bline1);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if( bbline1[a] + dir[tem_in].distance < dir[temp_f].distance)
                    {
                        dir[temp_f].distance=dir[tem_in].distance+ bbline1[a] ;
                        dir[temp_f].direct=dir[tem_in].direct;
                        dir[temp_f].line=dir[tem_in].line;
                        dir[temp_f].type=dir[tem_in].type;
                        dir[temp_f].direct.push_back(search(temp_f , t));
                        dir[temp_f].type.push_back("bus");
                        dir[temp_f].line.push_back("line1");

                    }
            }
            
        }
        for(int a=index-2; a >= 0; a--)
        {
            temp_f= find_index(t , a+1, bline1);
            tem_in= find_index(t , a, bline1);
            if(saveVehicles[tem_in].get_vis()[i]==false)
            {
                if(bbline1[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ bbline1[a] ;
                dir[tem_in].direct=dir[tem_in].direct;
                dir[tem_in].line=dir[tem_in].line;
                dir[tem_in].type=dir[tem_in].type;
                dir[tem_in].direct.push_back(search(temp_f, t));
                dir[tem_in].type.push_back("bus");
                dir[tem_in].line.push_back("line1");
                
            }
            }
            
        } 
    }
    void operation::set_bus_line2(unordered_map<string , int> & t,  int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t ,index-1, bline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
            {
                if(dir[tem_in].distance + bbline2[index-1] + timeoftype[5]< dir[temp_f].distance)
                {
                    dir[temp_f].distance = dir[tem_in].distance +bbline2[index-1] + timeoftype[5];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("bus");
                    dir[temp_f].line.push_back("line2");

                }
                
            }
            }
            
        }
        if(index<bline2.size()-1)
        {
            temp_f= find_index(t ,index+1, bline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
               if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
            {
                if(dir[tem_in].distance + bbline2[index] + timeoftype[5]< dir[temp_f].distance)
                {
                    dir[temp_f].distance = dir[tem_in].distance + bbline2[index] + timeoftype[5];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("bus");
                    dir[temp_f].line.push_back("line2");
            
                }
                
            } 
            }
            
        }
        for(int a=index+1; a<bline2.size()-1; a++)
        {
            temp_f= find_index(t , a+1, bline2);
            tem_in= find_index(t , a, bline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if(bbline2[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ bbline2[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(tem_in , t));
                dir[temp_f].type.push_back("bus");
                dir[temp_f].line.push_back("line2");
               
            }
            }
            
        }
        for(int a=index-2; a>=0 ; a--)
        {
            temp_f= find_index(t , a+1, bline2);
            tem_in= find_index(t , a, bline2);
            if(saveVehicles[tem_in].get_vis()[i]==false)
            {
                if(bbline2[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ bbline2[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(temp_f, t));
                dir[tem_in].type.push_back("bus");
                dir[tem_in].line.push_back("line2");
                
                
            }
            }
            
        } 
        
    }
    void operation::set_bus_line3(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, bline3);
            if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
            {
                //  cout<<tem_in<<" k "<<saveVehicles[temp_f].get_vis()[i];
                //  cout<<search(tem_in, t)<<"  ";
                // cout<<dir[tem_in].distance<<" f ";
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + bbline3[index-1] + timeoftype[5]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +bbline3[index-1] + timeoftype[5];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("bus");
                    dir[temp_f].line.push_back("line3");
                
                }
                
            }
        }
        if(index<bline3.size()-1)
        {
            temp_f= find_index(t , index+1, bline3);
            if( dir[tem_in].line.size()==0 ||  dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="bus")
            {
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + bbline3[index] + timeoftype[5]< dir[temp_f].distance )
                {
                    dir[temp_f].distance=dir[tem_in].distance + bbline3[index] + timeoftype[5];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("bus");
                    dir[temp_f].line.push_back("line3");
                    
                }
                
            }
        }
        for(int a=index+1; a<bline3.size()-1; a++)
        {
            temp_f= find_index(t , a+1, bline3);
            tem_in= find_index(t , a, bline3);
            if(!saveVehicles[temp_f].get_vis()[i] && bbline3[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ bbline3[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(tem_in, t));
                dir[temp_f].type.push_back("bus");
                dir[temp_f].line.push_back("line3");
               
            }
        }
        for(int a=index-2; a>=0 ; a--)
        {
            temp_f= find_index(t , a+1, bline3);
            tem_in= find_index(t , a, bline3);
            if(!saveVehicles[tem_in].get_vis()[i] &&bbline3[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ bbline3[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("bus");
                dir[tem_in].line.push_back("line3");
                
               
            }
        } 
        
    }
    void operation::set_sub_line1(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline1);
            if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + ssline1[index-1] + timeoftype[3]< dir[temp_f].distance )
                {
                    dir[temp_f].distance =dir[tem_in].distance + ssline1[index-1] + timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line1");

                }
                
            }
        }
        if(index<sline1.size()-1)
        {
            temp_f= find_index(t , index+1, sline1);
            if(dir[tem_in].line.size()==0 ||  dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if( !saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ssline1[index] + timeoftype[3]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +ssline1[index] + timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line1");
 
                }
                
            }
        }
        for(int a = index+1; a<sline1.size()-1; a++)
        {
             temp_f= find_index(t , a+1, sline1);
             tem_in= find_index(t , a, sline1);

            if( !saveVehicles[temp_f].get_vis()[i] &&ssline1[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ssline1[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search( temp_f, t));
                dir[temp_f].type.push_back("subway");
                dir[temp_f].line.push_back("line1");

            }
        }
        for(int a=index-2; a>=0 ; a--)
        {
             temp_f= find_index(t , a+1, sline1);
             tem_in= find_index(t , a, sline1);
            if( !saveVehicles[tem_in].get_vis()[i] &&ssline1[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ssline1[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(temp_f, t));
                dir[tem_in].type.push_back("subway");
                dir[tem_in].line.push_back("line1");

               
            }
        }


    }
    void operation::set_sub_line2(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + ssline2[index-1] + timeoftype[3]< dir[temp_f].distance )
                {
                    
                    dir[temp_f].distance =dir[tem_in].distance + ssline2[index-1]+ timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line2");

                }
                
            }
            } 
        }
        if(index<sline2.size()-1)
        {
            temp_f= find_index(t , index+1, sline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if(dir[tem_in].line.size()==0 ||  dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(dir[tem_in].distance + ssline2[index] + timeoftype[3]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +ssline2[index] + timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line2");

                }
            }
            }
            
        }
        for(int a=index+1; a<sline2.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline2);
            tem_in= find_index(t , a, sline2);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
                if(ssline2[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ssline2[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("subway");
                dir[temp_f].line.push_back("line2");
 
            }
            }
            
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline2);
            tem_in= find_index(t , a, sline2);
            if(saveVehicles[tem_in].get_vis()[i]==false)
            {
                if(!saveVehicles[tem_in].get_vis()[i] && ssline2[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ssline2[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("subway");
                dir[tem_in].line.push_back("line2");

               
            }
            }
            
        }

    }
    void operation::set_sub_line3(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count, int i)
    {
        int temp_f;
        int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline3);
            if(saveVehicles[temp_f].get_vis()[i]==false)
            {
            if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if( dir[tem_in].distance + ssline3[index-1] + timeoftype[3]< dir[temp_f].distance)
                {
                    dir[temp_f].distance = dir[tem_in].distance +ssline3[index-1]+ timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line3"); 
 
                }
                
            }
            }
            
        }
        if(index<sline3.size()-1)
        {
            temp_f= find_index(t , index+1, sline3);
            if(dir[tem_in].line.size()==0 ||dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ssline3[index] + timeoftype[3]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +ssline3[index] + timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line3");

                }
                
            }
        }
        for(int a=index+1; a<sline3.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline3);
            tem_in= find_index(t , a, sline3);
            if(!saveVehicles[temp_f].get_vis()[i] && ssline3[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ssline3[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("subway");
                dir[temp_f].line.push_back("line3");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline3);
            tem_in= find_index(t , a, sline3);
            if(!saveVehicles[tem_in].get_vis()[i] &&ssline3[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ssline3[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("subway");
                dir[tem_in].line.push_back("line3");

            }
        }

    }
    void operation::set_sub_line4(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count , int i)
    {
        int temp_f;
        int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline4);
            if(dir[tem_in].line.size()==0 ||  dir[tem_in].line[dir[tem_in].line.size()-1]!="line4" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ssline4[index-1] + timeoftype[3]< dir[temp_f].distance )
                {
                    dir[temp_f].distance =dir[tem_in].distance + ssline4[index-1]+ timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line4"); 

                }
               
            }
        }
        if(index<sline4.size()-1)
        {
            temp_f= find_index(t , index+1, sline4);
            if( dir[tem_in].line.size()==0 ||dir[tem_in].line[dir[tem_in].line.size()-1]!="line4" || dir[tem_in].type[dir[tem_in].type.size()-1]!="subway")
            {
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + ssline4[index] + timeoftype[3]< dir[temp_f].distance )
                {
                    dir[temp_f].distance=dir[tem_in].distance + ssline4[index] + timeoftype[3];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("subway");
                    dir[temp_f].line.push_back("line4");

                }
                
            }
        }
        for(int a=index+1; a<sline4.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline4);
            tem_in= find_index(t , a, sline4);
            if(!saveVehicles[temp_f].get_vis()[i] &&ssline4[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ssline4[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("subway");
                dir[temp_f].line.push_back("line4");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline4);
            tem_in= find_index(t , a, sline4);
            if(!saveVehicles[tem_in].get_vis()[i]&&ssline4[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ssline4[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("subway");
                dir[tem_in].line.push_back("line4");
                
            }
        }

    }
    void operation::set_taxi_line1(unordered_map<string , int> & t, int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count , int i)
    {

       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline1);
            if( dir[tem_in].line.size()==0 ||  dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ttline1[index-1] + timeoftype[4]< dir[temp_f].distance )
                {
                    dir[temp_f].distance =dir[tem_in].distance + ttline1[index-1]+ timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line1");  

                }
                
            }
        }
        if(index<sline1.size()-1)
        {
            temp_f= find_index(t , index+1, sline1);
            if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line1" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if( !saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ttline1[index] + timeoftype[4]< dir[temp_f].distance)
                {
                    
                    dir[temp_f].distance=dir[tem_in].distance + ttline1[index] + timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line1");
  
                }
                
            }
        }
        for(int a=index+1; a<sline1.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline1);
            tem_in= find_index(t , a, sline1);
            if(!saveVehicles[temp_f].get_vis()[i] &&ttline1[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ttline1[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("taxi");
                dir[temp_f].line.push_back("line1");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline1);
            tem_in= find_index(t , a, sline1);
            if(!saveVehicles[tem_in].get_vis()[i] &&ttline1[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ttline1[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("taxi");
                dir[tem_in].line.push_back("line1");

               
            }
        }
    }
    void operation::set_taxi_line2(unordered_map<string , int> & t,  int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count , int i )
    {
        int temASL=tem_in;
        int temp_f;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline2);
            if( dir[tem_in].line.size()==0 ||dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + ttline2[index-1] + timeoftype[4]< dir[temp_f].distance )
                {
                    dir[temp_f].distance =dir[tem_in].distance + ttline2[index-1]+ timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line2");
 
                }
                
            }
        }
        if(index<sline2.size()-1)
        {
            temp_f= find_index(t , index+1, sline2);
            if( dir[tem_in].line.size()==0 ||dir[tem_in].line[dir[tem_in].line.size()-1]!="line2" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ttline2[index] + timeoftype[4]< dir[temp_f].distance)
                {
                    dir[temp_f].distance=dir[tem_in].distance + ttline2[index] + timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line2");

                }
                
            }
        }
        for(int a=index+1; a<sline2.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline2);
            tem_in= find_index(t , a, sline2);
            if(!saveVehicles[temp_f].get_vis()[i]&&ttline2[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ttline2[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("taxi");
                dir[temp_f].line.push_back("line2");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline2);
            tem_in= find_index(t , a, sline2);
            if(!saveVehicles[tem_in].get_vis()[i]&&ttline2[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ttline2[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("taxi");
                dir[tem_in].line.push_back("line2");

               
            }
        }
    }
    void operation::set_taxi_line3(unordered_map<string , int> & t,  int index, int tem_in, vector<int> timeoftype, saveDirect dir[V], int count , int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline3);
            if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                
                if(!saveVehicles[temp_f].get_vis()[i]&&dir[tem_in].distance + ttline3[index-1] + timeoftype[4]< dir[temp_f].distance )
                {
                    dir[temp_f].distance = dir[tem_in].distance +ttline3[index-1]+ timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line3");

                }
                
            }
        }
        if(index<sline3.size()-1)
        {
            temp_f= find_index(t , index+1, sline3);
            if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line3" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if(!saveVehicles[temp_f].get_vis()[i]&&dir[tem_in].distance + ttline3[index] + timeoftype[4]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +ttline3[index] + timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line3");


                }
                
            }
        }
        for(int a=index+1; a<sline3.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline3);
            tem_in= find_index(t , a, sline3);
            if(!saveVehicles[temp_f].get_vis()[i]&&ttline3[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ttline3[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("taxi");
                dir[temp_f].line.push_back("line3");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline3);
            tem_in= find_index(t , a, sline3);
            if(!saveVehicles[tem_in].get_vis()[i]&&ttline3[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ttline3[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("taxi");
                dir[tem_in].line.push_back("line3");

              
            }
        }
 
    }
    void operation::set_taxi_line4(unordered_map<string , int> & t,  int index, int tem_in, vector<int> timeoftype, saveDirect dir[V],int count , int i)
    {
       int temp_f;
       int temASL=tem_in;
        if(index>0)
        {
            temp_f= find_index(t , index-1, sline4);
            if( dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line4" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if(!saveVehicles[temp_f].get_vis()[i] && dir[tem_in].distance + ttline4[index-1] + timeoftype[4]< dir[temp_f].distance)
                {
                    dir[temp_f].distance =dir[tem_in].distance + ttline4[index-1]+ timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line4");

                }
                
            }
        }
        if(index<sline4.size()-1)
        {
            temp_f= find_index(t , index+1, sline4);
            if(dir[tem_in].line.size()==0 || dir[tem_in].line[dir[tem_in].line.size()-1]!="line4" || dir[tem_in].type[dir[tem_in].type.size()-1]!="taxi")
            {
                if(!saveVehicles[temp_f].get_vis()[i] &&dir[tem_in].distance + ttline4[index] + timeoftype[4]< dir[temp_f].distance)
                {
                    dir[temp_f].distance= dir[tem_in].distance +ttline4[index] + timeoftype[4];
                    dir[temp_f].direct=dir[tem_in].direct;
                    dir[temp_f].line=dir[tem_in].line;
                    dir[temp_f].type=dir[tem_in].type;
                    dir[temp_f].direct.push_back(search(temp_f, t));
                    dir[temp_f].type.push_back("taxi");
                    dir[temp_f].line.push_back("line4"); 

                 }
                
            }
        }
        for(int a=index+1; a<sline4.size()-1; a++)
        {
            temp_f= find_index(t , a+1, sline4);
            tem_in= find_index(t , a, sline4);
            if(!saveVehicles[temp_f].get_vis()[i]&&ttline4[a] + dir[tem_in].distance < dir[temp_f].distance)
            {
                dir[temp_f].distance=dir[tem_in].distance+ ttline4[a] ;
                dir[temp_f].direct=dir[tem_in].direct;
                dir[temp_f].line=dir[tem_in].line;
                dir[temp_f].type=dir[tem_in].type;
                dir[temp_f].direct.push_back(search(temp_f , t));
                dir[temp_f].type.push_back("taxi");
                dir[temp_f].line.push_back("line4");

            }
        }
        for(int a=index-2; a>=0; a--)
        {
            temp_f= find_index(t , a+1, sline4);
            tem_in= find_index(t , a, sline4);
            if(!saveVehicles[tem_in].get_vis()[i] && ttline4[a] + dir[temp_f].distance < dir[tem_in].distance)
            {
                dir[tem_in].distance=dir[temp_f].distance+ ttline4[a] ;
                dir[tem_in].direct=dir[temp_f].direct;
                dir[tem_in].line=dir[temp_f].line;
                dir[tem_in].type=dir[temp_f].type;
                dir[tem_in].direct.push_back(search(tem_in, t));
                dir[tem_in].type.push_back("taxi");
                dir[tem_in].line.push_back("line4");
                
            }
        }

    }
    void operation:: show()
    {
        for(auto a:sline3)
        cout<<a<<" - ";

        for(auto b:ssline3)
        cout<<b<<" * ";
    }


