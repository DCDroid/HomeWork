#pragma once

#include "Figure.h"

class Triangle : public Figure{
protected:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Triangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B, uint32_t C);
    void print();
    void check();
};