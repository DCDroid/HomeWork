#pragma once
#include "Parallelogram.h"

class RightAngledQuadrangle : public Parallelogram {
public:
    RightAngledQuadrangle(uint32_t a, uint32_t b);
    void print();
    void check(); 
};