#include <iostream>
#include <unordered_map>
#include "Operation.hpp"

#define V 59
using namespace std;


void setItems(unordered_map<string , int> t, DataType m [V][V])
{
    int dis, j=0;
    string dataline1,dataline2,num;
    ifstream stfile("bus_Routes.txt");
    if (stfile.is_open())
    { 
        while (stfile) 
        {
            getline (stfile, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
            getline (stfile, dataline1); //station1
            getline (stfile, dataline2); //station2
            
            bool flag1=true, flag2=true;

            if (t.find(dataline1)!=t.end())
                flag1=false;
            if (t.find(dataline2)!=t.end())
                flag2=false;
                
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
            getline (stfile, num);
            dis = stoi(num); 
            m[t[dataline1]][t[dataline2]].set_dis(dis);
            m[t[dataline2]][t[dataline1]].set_dis(dis);
        }
    }
    stfile.close();  
    ifstream stfile("subway_Routes.txt");
    if (stfile.is_open())
    {
        while (stfile) 
        {
            getline (stfile, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
            getline (stfile, dataline1); //station1
            getline (stfile, dataline2); //station2
            
            bool flag1=true, flag2=true;

            if (t.find(dataline1)!=t.end())
                flag1=false;
            if (t.find(dataline2)!=t.end())
                flag2=false;
                
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
            getline (stfile, num);
            dis = stoi(num); 
            m[t[dataline1]][t[dataline2]].set_dis(dis);
            m[t[dataline2]][t[dataline1]].set_dis(dis);
            
        }
    } 
    stfile.close();  

    ifstream stfile("taxi_Routes.txt");
    if (stfile.is_open())
    {
        while (stfile) 
        {
            getline (stfile, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
            getline (stfile, dataline1); //station1
            getline (stfile, dataline2); //station2
            
            bool flag1=true, flag2=true;

            if (t.find(dataline1)!=t.end())
                flag1=false;
            if (t.find(dataline2)!=t.end())
                flag2=false;
                
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
            getline (stfile, num);
            dis = stoi(num); 
            m[t[dataline1]][t[dataline2]].set_dis(dis);
            m[t[dataline2]][t[dataline1]].set_dis(dis);
            
        }
    } 
    stfile.close();  

}

int operation::getIndex(unordered_map<string , int> t,string stn)
{
    if (t.find(stn)==t.end())
        throw "this index does not exist";  
        
    return t[stn];
}

