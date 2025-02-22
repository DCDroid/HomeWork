#include "Square.h"

Square::Square(uint32_t a) : Rhombus(a, 90, 90)
{
    this->name = "Square: ";
    check();

    if(correct == false) {
        throw ConstructorError("Error creating square. Reason: not all sides are equal, not all angles are equal to 90");
    }
}

void Square::check() {
    correct &= (a == c && b == d && a == b) && (A == 90 && B == 90 && C == 90 && D == 90);
}

void Square::print() {
    std::cout << "Square (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") created.\n";
}
    