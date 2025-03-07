#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(uint32_t a, uint32_t b, uint32_t A) : Triangle(a, b, a, A, 180 - 2 * A, A) {
    this->name = "IsoscelesTriangle: ";
}
    