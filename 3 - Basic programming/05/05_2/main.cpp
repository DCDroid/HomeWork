#include <iostream>

class Figure 
{
protected: 
    std::string name{"Figure: "};
public:
    std::string get_name()
    {
        return this->name;
    }
    virtual void print() = 0;
};

class Triangle : public Figure{
private:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Triangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B, uint32_t C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Triangle: ";
    }
    void print() {
        std::cout << this->name << std::endl;
        std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
        std::cout << "A = " << A << " B = " << B << " C = " << C << "\n\n";
    }
};

class RightAngledTriangle : public Triangle {
public:
    RightAngledTriangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B) : Triangle(a, b, c, A, B, 90) {
        name = "RightAngledTriangle: ";
        if (180 - A - B != 90) {
            std::cout << "Not right angled triangle" << std::endl;
        }
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(uint32_t a) : Triangle(a, a, a, 60, 60, 60) {
        name = "EquilateralTriangle: ";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(uint32_t a, uint32_t b, uint32_t A) : Triangle(a, b, a, A, 180 - 2 * A, A) {
        name = "IsoscelesTriangle: ";
    }
};

class Quadrangle : public Figure {
private:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Quadrangle(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        name = "Quadrangle: ";
    }
    void print() {
        std::cout << this->name << std::endl;
        std::cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
        std::cout << "A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n\n";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(uint32_t a, uint32_t b, uint32_t A, uint32_t B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Parallelogram: ";
    }
};

class RightAngledQuadrangle : public Parallelogram {
public:
    RightAngledQuadrangle(uint32_t a, uint32_t b) : Parallelogram(a, b, 90, 90) {
        name = "RightAngledQuadrangle: ";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(uint32_t a, uint32_t A, uint32_t B) : Parallelogram(a, a, A, B) {
        name = "Rhombus: ";
    }
};

class Square : public Rhombus {
public:
    Square(uint32_t a) : Rhombus(a, 90, 90) {
        name = "Square: ";
    }
};

void print_info(Figure* figure) {
    figure->print();
}

int main()
{
    Triangle my_triangle(10, 20, 30, 50, 60, 70);
    print_info(&my_triangle);

    RightAngledTriangle my_right_angled_triangle(10, 20, 30, 30, 60);
    print_info(&my_right_angled_triangle);

    IsoscelesTriangle my_isosceles_triangle(10, 20, 10);
    print_info(&my_isosceles_triangle);

    EquilateralTriangle my_equilateral_triangle(30);
    print_info(&my_equilateral_triangle);

    Quadrangle my_quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&my_quadrangle);

    RightAngledQuadrangle my_right_angled_quadrangle(10, 20);
    print_info(&my_right_angled_quadrangle);

    Square my_square(20);
    print_info(&my_square);

    Parallelogram my_parallelogram(20, 30, 30, 40);
    print_info(&my_parallelogram);

    Rhombus my_rhombus(30, 30, 40);
    print_info(&my_rhombus);
}