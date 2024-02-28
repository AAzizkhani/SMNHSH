#include <iostream>
#include <fstream> 
#include <vector>
#include <unordered_map>
#include "Operation.hpp"
#include <set>
#define V 59
using namespace std;


    void operation::read_cost( char type, vector <int> costs, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V], int hour )
    {
        string line,dataline1,dataline2,num;
        int dis;
         while (!stfile1.eof()) 
            {
            getline (stfile1, line); //.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            getline (stfile1, num); dis=stoi(num);
            if(type=='b')
            {
                
                m[t[dataline1]][t[dataline2]].set_time(costs[2]);
                m[t[dataline2]][t[dataline1]].set_time(costs[2]);
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("bus");
                m[t[dataline2]][t[dataline1]].set_timeType("bus");

            }
            if(type=='s')
            {
                
                m[t[dataline1]][t[dataline2]].set_time(costs[1]);
                m[t[dataline2]][t[dataline1]].set_time(costs[1]);
                m[t[dataline1]][t[dataline2]].set_timeLine(line);
                m[t[dataline2]][t[dataline1]].set_timeLine(line);
                m[t[dataline1]][t[dataline2]].set_timeType("subway");
                m[t[dataline2]][t[dataline1]].set_timeType("subway");
            }

            if(type=='t')
            {
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
                    m[t[dataline1]][t[dataline2]].set_time((timeOfType[2]*dis*2));
                    m[t[dataline2]][t[dataline1]].set_time((timeOfType[2]*dis*2));
                }
                else
                {
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
                    m[t[dataline1]][t[dataline2]].set_time((timeOfType[0]*dis*2));
                    m[t[dataline2]][t[dataline1]].set_time((timeOfType[0]*dis*2));
                }
                else
                {
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
        static int j;
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
                j++;     
            }
            if(flag2)
            {
                t[dataline2]=j;
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
        read_cost('b',costs, stfile, t, m, hour);
    }  
    stfile.close();

    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
        read_cost('s',costs, stfile1, t, m, hour);
    }
    stfile1.close();

    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile2.is_open())
    {
        read_cost('t',costs, stfile2, t, m, hour);
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
            m[i][j].set_dis(0);
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

