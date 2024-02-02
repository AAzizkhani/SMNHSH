#include <iostream>
#include <unordered_map>
#include <fstream>
#include <exception>

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

    public:

        void set_items(int dis, int cost)
        {
            distance=dis;
            this->cost=cost;
        }
        int get_cost()
        {
            return cost;
        }
        int get_dis()
        {
            return distance;
        }

    
};

//Operations such as assigning index with map

class operation
{
    public:

    void set_index(unordered_map<string , int> t,data_type m )
    {
        ifstream stfile("stfile.txt");
        if (stfile.is_open())
        {
            int j=0;
            string dataline1,dataline2; 
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
                getline (stfile, dataline2); //faghed ahamiyat. distance
            }
        }  
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

    data_type stations[61][61];

    operation operatorr;

    operatorr.set_index(index, stations[61][61]);

    

}