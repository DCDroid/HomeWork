#include "Triangle.h"

Triangle::Triangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B, uint32_t C)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    name = "Triangle: ";
    side_count = 3;
    check();

    if(correct == false) {
        throw ConstructorError("Error creating triangle. Reason: sum of angles does not equal 180");
    }
}

void Triangle::print()
{
    std::cout << "Triangle (sides: " << a << ", " << b << ", " << c << "; angles: " << A << ", " << B << ", " << C << ") created.\n";
}

void Triangle::check()
{
    if ((A + B + C == 180) && (side_count == 3)) correct = true;
    else correct = false;
}
