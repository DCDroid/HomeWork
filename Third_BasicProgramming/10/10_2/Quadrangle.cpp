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
}
void Quadrangle::print() {
    std::cout << this->name << std::endl;
    std::cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
    std::cout << "A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n\n";
}