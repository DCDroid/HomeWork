#include "RightAngledTriangle.h"

RightAngledTriangle::RightAngledTriangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B) : Triangle(a, b, c, A, B, (180 - A - B))
{
    this->name = "RightAngledTriangle: ";
    RightAngledTriangle::check();

    if(correct == false) {
        throw ConstructorError("Error creating figure. Reason: angle C is not 90 degrees");
    }
}

void RightAngledTriangle::check()
{
    if (180 - this->A - this->B == 90) this->correct &= true;
    else this->correct &= false;
}

void RightAngledTriangle::print()
{
    std::cout << "Right angled triangle (sides: " << a << ", " << b << ", " << c << "; angles: " << A << ", " << B << ", " << C << ") created.\n";
}