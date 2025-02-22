#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(uint32_t a, uint32_t b, uint32_t A) : Triangle(a, b, a, A, 180 - 2 * A, A) {
    this->name = "IsoscelesTriangle: ";
    check();

    if(correct == false) {
        throw ConstructorError("Error creating isosceles triangle. Reason: sides a and c are not equal or angles A and C are not equal");
    }
}

void IsoscelesTriangle::print()
{
    std::cout << "Isosceles triangle (sides: " << a << ", " << b << ", " << c << "; angles: " << A << ", " << B << ", " << C << ") created.\n";
}

void IsoscelesTriangle::check() {
    if (a == c && A == C) correct &= true;
    else correct &= false;
}


    