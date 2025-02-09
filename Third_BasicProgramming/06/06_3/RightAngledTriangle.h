#pragma once
#include "Triangle.h"

class RightAngledTriangle : public Triangle 
{
public:
    RightAngledTriangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B);
    void check();
};