#include <iostream>

class Figure 
{
protected: 
    std::string name{"Figure: "};
    int side_count{};
    bool correct{true};
public:
    Figure() 
    {
        check();
    }
    std::string get_name()
    {
        return this->name;
    }
    virtual void print() {
        std::cout << this->name << std::endl;
        if (correct) std::cout << "Good" << std::endl; else std::cout << "Bad" << std::endl;
        std::cout << "Side count: " << this->side_count << "\n\n";
    }
    virtual void check() {
        if(side_count == 0) correct = true;
        else correct = false;
    }
};

class Triangle : public Figure{
protected:
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
        side_count = 3;
        check();
    }
    void print() {
        std::cout << this->name << std::endl;
        if (correct) std::cout << "Good" << std::endl; else std::cout << "Bad" << std::endl;
        std::cout << "Side_count: " << this->side_count << std::endl;
        std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
        std::cout << "A = " << A << " B = " << B << " C = " << C << "\n\n";
    }
    void check() {
        if ((A + B + C == 180) && (side_count == 3)) correct = true;
        else correct = false;
    }
};

class RightAngledTriangle : public Triangle {
public:
    RightAngledTriangle(uint32_t a, uint32_t b, uint32_t c, uint32_t A, uint32_t B) : Triangle(a, b, c, A, B, 90) {
        name = "RightAngledTriangle: ";
        check();
    }
    void check() {
        if (180 - A - B == 90) correct &= true;
        else correct &= false;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(uint32_t a) : Triangle(a, a, a, 60, 60, 60) {
        name = "EquilateralTriangle: ";
        check();
    }
    void check() {
        if (a == b && b == c && A == B && B == C) correct &= true;
        else correct &= false;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(uint32_t a, uint32_t b, uint32_t A) : Triangle(a, b, a, A, 180 - 2 * A, A) {
        name = "IsoscelesTriangle: ";
        check();
    }
    void check() {
        if (a == c && A == C) correct &= true;
        else correct &= false;
    }
};

class Quadrangle : public Figure {
protected:
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
        side_count = 4;
        check();
    }
    void print() {
        std::cout << this->name << std::endl;
        if (correct) std::cout << "Good" << std::endl; else std::cout << "Bad" << std::endl;
        std::cout << "Side_count: " << this->side_count << std::endl;
        std::cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << std::endl;
        std::cout << "A = " << A << " B = " << B << " C = " << C << " D = " << D << "\n\n";
    }
    void check() {
        correct = (side_count == 4) && (A + B + C + D == 360);
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(uint32_t a, uint32_t b, uint32_t A, uint32_t B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Parallelogram: ";
        check();
    }
    void check() {
        correct &= (a == c && b == d) && (A == C && B == D);
    }
};

class RightAngledQuadrangle : public Parallelogram {
public:
    RightAngledQuadrangle(uint32_t a, uint32_t b) : Parallelogram(a, b, 90, 90) {
        name = "RightAngledQuadrangle: ";
        check();
    }
    void check() {
        correct &= (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(uint32_t a, uint32_t A, uint32_t B) : Parallelogram(a, a, A, B) {
        name = "Rhombus: ";
        check();
    }
    void check() {
        correct &= (a == c && b == d && a == b) && (A == C && B == D);
    }
};

class Square : public Rhombus {
public:
    Square(uint32_t a) : Rhombus(a, 90, 90) {
        name = "Square: ";
        check();
    }
    void check() {
        correct &= (a == c && b == d && a == b) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

void print_info(Figure* figure) {
    figure->print();
}

int main()
{
    Figure my_figure;
    print_info(&my_figure);

    Triangle my_triangle(10, 20, 30, 50, 60, 70);
    print_info(&my_triangle);

    RightAngledTriangle my_right_angled_triangle(10, 20, 30, 50, 60);
    print_info(&my_right_angled_triangle);

    RightAngledTriangle my_right_angled_triangle_2(10, 20, 30, 50, 40);
    print_info(&my_right_angled_triangle_2);

    IsoscelesTriangle my_isosceles_triangle(10, 10, 40);
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