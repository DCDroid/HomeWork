#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Quadrangle(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t A, uint32_t B, uint32_t C, uint32_t D) ;
    void print();
    void check();
};