#include <iostream>

#include "FigureHeaders.h"

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