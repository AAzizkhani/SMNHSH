#ifndef  TL_HPP
#define TL_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <unordered_map>
#include "DataType.hpp"

using namespace std;

class vectors
{
    private:
        vector<string>bline1;
        vector<string>bline2;
        vector<string>bline3;
        vector<string>sline1;
        vector<string>sline2;
        vector<string>sline3;
        vector<string>sline4;

    public:
        vector<string> get_b1();
        vector<string> get_b2();
        vector<string> get_b3();
        vector<string> get_s1();
        vector<string> get_s2();
        vector<string> get_s3();
        vector<string> get_s4();
        void set_b1(string station);
        void set_b2(string station);
        void set_b3(string station);
        void set_s1(string station);
        void set_s2(string station);
        void set_s3(string station);
        void set_s4(string station);
        read file()



};
#endif