#include <iostream>
#include <fstream> 
#include <vector>
#include <unordered_map>
#include "Operation.hpp"
#include <set>
#define V 59
using namespace std;


void operation::read_cost( char type, vector <int> costs, ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V] )
{
    string dataline1,dataline2,num;
    int dis;
    while (!stfile1.eof()) 
        {
            getline (stfile1, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
            getline (stfile1, dataline1); //station1
            getline (stfile1, dataline2); //station2
            if(type=='b')
            {
            m[t[dataline1]][t[dataline2]].set_dis(costs[2]);
            m[t[dataline2]][t[dataline1]].set_dis(costs[2]);
            }
            if(type=='s')
            {
            m[t[dataline1]][t[dataline2]].set_dis(costs[1]);
            m[t[dataline2]][t[dataline1]].set_dis(costs[1]);   
            }
            getline (stfile1, num);
            if(type=='t')
            {
                dis=stoi(num);
                m[t[dataline1]][t[dataline2]].set_dis((costs[0]*dis));
                m[t[dataline2]][t[dataline1]].set_dis((costs[0]*dis));  
            }
                       
        }
}

void operation::read_dis(string type,ifstream &stfile1, unordered_map<string , int> & t, DataType m [V][V] )
{
    int dis;
    static int j;
    string dataline1,dataline2 , num;
    while (!stfile1.eof()) 
        {
            getline (stfile1, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
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

            }
        }
}
void operation::setItems_dis(unordered_map<string , int> & t, DataType m [V][V])
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
    if (stfile2.is_open())
    {
        read_dis("taxi", stfile2, t, m);
       
    } 
    stfile2.close();  

}
void operation:: setItems_cost(unordered_map<string , int> &t, DataType m[V][V])
{
    vector <int> costs;
    ifstream costfile;
    string price;
    int cost;
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
        read_cost('b',costs, stfile, t, m);
    }  
    stfile.close();
    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
        read_cost('s',costs, stfile1, t, m);

    } 
    stfile1.close();  

    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile2.is_open())
    {
        read_cost('t',costs, stfile2, t, m);
       
    } 
    stfile2.close(); 


}

int operation::getIndex(unordered_map<string , int> t,string stn)
{
    if (t.find(stn)==t.end())
        throw invalid_argument("this index does not exist");  
        
    return t[stn];
}

