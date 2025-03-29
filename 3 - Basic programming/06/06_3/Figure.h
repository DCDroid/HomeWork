#pragma once
#include <iostream>

class Figure 
{
protected: 
    std::string name{"Figure: "};
    int side_count{};
    bool correct{true};
public:
    Figure();
    std::string get_name();
    virtual void print();
    virtual void check();
};