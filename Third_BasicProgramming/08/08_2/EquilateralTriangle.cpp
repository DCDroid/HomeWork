#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(uint32_t a) : Triangle(a, a, a, 60, 60, 60) {
    this->name = "EquilateralTriangle: ";
    EquilateralTriangle::check();

    if(correct == false) {
        throw ConstructorError("Error creating equilateral triangle. Reason: not all sides are equal, not all angles are equal to 60");
    }
}

void EquilateralTriangle::print()
{
    std::cout << "Equilateral triangle (sides: " << a << ", " << b << ", " << c << "; angles: " << A << ", " << B << ", " << C << ") created.\n";
}

void EquilateralTriangle::check() {
    if (a == b && b == c && A == B && B == C) correct &= true;
    else correct &= false;
}
    