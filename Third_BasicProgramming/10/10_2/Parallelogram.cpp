#include "Parallelogram.h"

Parallelogram::Parallelogram(uint32_t a, uint32_t b, uint32_t A, uint32_t B) : Quadrangle(a, b, a, b, A, B, A, B) 
{
    this->name = "Parallelogram: ";
}