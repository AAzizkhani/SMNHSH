#ifdef  DATATYPE_HPP
#define DATATYPE_HPP

#include <iostream>

class DataType
{

private:
    int distance=0;
    int cost=0;
    std::string path;

public:
    void set_dis(int);
    void set_cost(int);
    void set_pathh(string);

    int get_cost();
    int get_dis();
    string get_path();
};

#endif