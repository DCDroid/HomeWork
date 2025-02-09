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
}

void Triangle::print()
{
    std::cout << this->name << std::endl;
    if (correct) std::cout << "Good" << std::endl; else std::cout << "Bad" << std::endl;
    std::cout << "Side_count: " << this->side_count << std::endl;
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
    std::cout << "A = " << A << " B = " << B << " C = " << C << "\n\n";
}
void Triangle::check()
{
    if ((A + B + C == 180) && (side_count == 3)) correct = true;
    else correct = false;
}
