#include <iostream>
#include <fstream> 
#include <unordered_map>
#include "Operation.hpp"

#define V 59
using namespace std;


void operation::setItems(unordered_map<string , int> & t, DataType m [V][V])
{
    int dis, j=0;
    string dataline1,dataline2 , num;
    ifstream stfile;
    stfile.open("bus_Routes.txt", ios::in);

    if (stfile.is_open())
    { 
        while (stfile) 
        {
            getline (stfile, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
            getline (stfile, dataline1); //station1
            getline (stfile, dataline2); //station2
           
            
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
            getline (stfile, num);
            dis = stoi(num); 
            if( m[t[dataline1]][t[dataline2]].get_dis()>dis|| m[t[dataline1]][t[dataline2]].get_dis() == 0)
            {
                m[t[dataline1]][t[dataline2]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_pathh("bus");
                m[t[dataline1]][t[dataline2]].set_pathh("bus");


            }

        }
       
    }  
    stfile.close();
    ifstream stfile1;
    stfile1.open("subway_Routes.txt", ios::in);
    if (stfile1.is_open())
    {
        while (stfile1) 
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
                m[t[dataline2]][t[dataline1]].set_pathh("subway");
                m[t[dataline1]][t[dataline2]].set_pathh("subway");
            }    
            
        }
    } 
    stfile1.close();  

    ifstream stfile2;
    stfile2.open("taxi_Routes.txt", ios::in);
    if (stfile2.is_open())
    {
        while (stfile2) 
        {
            getline (stfile2, dataline1); //faghed ahamiyat.firs line. bs1/sub1/tax1/...
          
            getline (stfile2, dataline1); //station1
      
            getline (stfile2, dataline2); //station2
            
            
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
            getline (stfile2, num);
            dis = stoi(num); 
            if( m[t[dataline1]][t[dataline2]].get_dis()>dis || m[t[dataline1]][t[dataline2]].get_dis() == 0 )
            {
                m[t[dataline1]][t[dataline2]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_dis(dis);
                m[t[dataline2]][t[dataline1]].set_pathh("taxi");
                m[t[dataline1]][t[dataline2]].set_pathh("taxi");
            }     
        }
    } 
    stfile2.close();  

}

int operation::getIndex(unordered_map<string , int> t,string stn)
{
    if (t.find(stn)==t.end())
        throw invalid_argument("this index does not exist");  
        
    return t[stn];
}

