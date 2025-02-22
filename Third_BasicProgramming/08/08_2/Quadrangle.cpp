#include "Quadrangle.h"

Quadrangle::Quadrangle(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->name = "Quadrangle: ";
    side_count = 4;
    check();

    if(correct == false) {
        throw ConstructorError("Error creating quadrangle. Reason: the sum of the angles does not equal 360");
    }
}
void Quadrangle::print() {
    std::cout << "Quadrangle (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") created.\n";
}
void Quadrangle::check() {
    correct = (side_count == 4) && (A + B + C + D == 360);
}

