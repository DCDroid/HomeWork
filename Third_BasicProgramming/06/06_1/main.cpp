#include <iostream>
#include "math_fun.h"

int main()
{
    float first_number{}, second_number{}, res{};
    uint32_t operation{};
    std::cout << "Enter first number: ";
    std::cin >> first_number;
    std::cout << "Enter second number: ";
    std::cin >> second_number;
    std::cout << "Enter operation (1 - sum, 2 - sub, 3 - mul, 4 - div, 5 - power)" << std::endl;
    std::cin >> operation;

    switch (operation)
    {
    case 1:
        res = sum(first_number, second_number);
        std::cout << first_number << " + " << second_number << " = " << res << std::endl;
        break;
    case 2:
        res = sub(first_number, second_number);
        std::cout << first_number << " - " << second_number << " = " << res << std::endl;
        break;
    case 3:
        res = mul(first_number, second_number);
        std::cout << first_number << " * " << second_number << " = " << res << std::endl;
        break;
    case 4:
        res = div(first_number, second_number);
        std::cout << first_number << " / " << second_number << " = " << res << std::endl;
        break;    
    case 5:
        res = power(first_number, second_number);
        std::cout << first_number << " power " << second_number << " = " << res << std::endl;
        break;
    default:
        break;
    }
}