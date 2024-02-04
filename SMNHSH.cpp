#include <iostream>
#include <unordered_map>
#include <fstream>
#include <exception>
#include <string>

using namespace std;

//does not matter

/*class MyException
{
    public:

    void error(int num)
    {
    
    switch (num) 
    { 
    case 1: 
        cout << "this index does not exist"; 
        break; 
    case 2: 
        cout << ""; 
        break; 
    case 3: 
        cout << ""; 
        break; 
    } 
    }
};*/


// for type of Adjatency Matrix
class data_type
{
    private:

        int distance=0;
        int cost=0;
        string path;

    public:

        void set_dis(int dis)
        {
            distance=dis;
        }
        void set_cost(int cost)
        {
            this->cost=cost;
        }
        void set_pathh(string path)
        {
            this->path=path;
        }
        int get_cost()
        {
            return cost;
        }
        int get_dis()
        {
            return distance;
        }
        string get_path()
        {
            return path;
        }

    
};


//Operations such as assigning index with map

class operation
{
    public:

    void set_items(unordered_map<string , int> t, data_type m [59][59])
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

    int get_index(unordered_map<string , int> t,string stn)
    {
        if (t.find(stn)==t.end())
           throw "this index does not exist";  
        
      return t[stn];
    }

};

int main()
{
    unordered_map<string ,  int> index;

    data_type stations[59][59];

    operation operatorr;

    operatorr.set_items(index, stations);

    

}