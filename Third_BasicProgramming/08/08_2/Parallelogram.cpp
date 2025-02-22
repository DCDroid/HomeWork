#include "Parallelogram.h"

Parallelogram::Parallelogram(uint32_t a, uint32_t b, uint32_t A, uint32_t B) : Quadrangle(a, b, a, b, A, B, A, B) 
{
    this->name = "Parallelogram: ";
    check();

    if(correct == false) {
        throw ConstructorError("Error creating parallelogram. Reason: sides a,c and b,d are not equal in pairs, angles A,C and B,D are not equal in pairs");
    }
}

void Parallelogram::check()
{
    correct &= (a == c && b == d) && (A == C && B == D);
}

void Parallelogram::print()
{
    std::cout << "Parallelogram (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") created.\n";
}