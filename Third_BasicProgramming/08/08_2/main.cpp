#include <iostream>

#include "FigureHeaders.h"
#include "ConstructorError.h"


void print_info(Figure* figure) {
    figure->print();
}


int main()
{

    try 
    {
        Triangle my_triangle(10, 20, 30, 50, 60, 10);
    }
    catch (const ConstructorError& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    try 
    {
        RightAngledTriangle my_right_angled_triangle(10, 20, 30, 60, 60);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }    
    
    try 
    {
        IsoscelesTriangle my_isosceles_triangle(10, 10, 40);
        print_info(&my_isosceles_triangle);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try 
    {
        EquilateralTriangle my_equilateral_triangle(30);
        print_info(&my_equilateral_triangle);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    try 
    {
        // Quadrangle my_quadrangle(10, 20, 30, 40, 90, 90, 90, 90);
        Quadrangle my_quadrangle(10, 20, 30, 40, 90, 90, 90, 80); // ex test
        print_info(&my_quadrangle);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try 
    {
        RightAngledQuadrangle my_right_angled_quadrangle(10, 20);
        print_info(&my_right_angled_quadrangle);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        Parallelogram my_parallelogram(20, 30, 100, 80);
        print_info(&my_parallelogram);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    try
    {
        Square my_square(20);
        print_info(&my_square);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    try
    {
        Rhombus my_rhombus(30, 100, 80);
        print_info(&my_rhombus);
    }
    catch (const ConstructorError& ex)
    {
        std::cout << ex.what() << std::endl;
    }   
    
}