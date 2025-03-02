#include "Rhombus.h"

Rhombus::Rhombus(uint32_t a, uint32_t A, uint32_t B) : Parallelogram(a, a, A, B) {
    this->name = "Rhombus: ";
    Rhombus::check();

    if(correct == false) {
        throw ConstructorError("Error creating rhombus. Reason: not all sides are equal, not all angles are equal to 90");
    }
}

void Rhombus::check() {
    correct &= (a == c && b == d && a == b) && (A == C && B == D);
}

void Rhombus::print() {
    std::cout << "Rhombus (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") created.\n";
}
    