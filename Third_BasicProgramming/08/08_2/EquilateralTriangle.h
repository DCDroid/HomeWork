#pragma once
#include "Triangle.h"

class EquilateralTriangle : public Triangle 
{
public:
    EquilateralTriangle(uint32_t a);
    void print();
    void check();
};