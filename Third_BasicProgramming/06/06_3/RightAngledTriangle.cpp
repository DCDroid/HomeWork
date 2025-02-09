#include "RightAngledTriangle.h"

RightAngledTriangle::RightAngledTriangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B) : Triangle(a, b, c, A, B, 90)
{
    this->name = "RightAngledTriangle: ";
    check();
}
void RightAngledTriangle::check()
{
    if (180 - this->A - this->B == 90) this->correct &= true;
    else this->correct &= false;
}