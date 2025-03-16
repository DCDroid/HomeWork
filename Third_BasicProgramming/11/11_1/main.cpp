#include "Greeter/Greeter.h"
#include <iostream>

int main()
{
    Greeter my_grateer;

    std::string name;

    std::cout << "Hi, enter  your name: ";
    std::cin >> name;
    std::cout << my_grateer.greet(name) << std::endl;

    return 0;
}