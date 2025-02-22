#include "RightAngledQuadrangle.h"

RightAngledQuadrangle::RightAngledQuadrangle(uint32_t a, uint32_t b) : Parallelogram(a, b, 90, 90) 
{
    this->name = "RightAngledQuadrangle: ";
    check();

    if(correct == false) {
        throw ConstructorError("Error creating right angled quadrangle. Reason: the sum of the angles does not equal 360");
    }
}

void RightAngledQuadrangle::check()
{
    correct &= (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
}

void RightAngledQuadrangle::print()
{
    std::cout << "Right angled quadrangle (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") created.\n";
}