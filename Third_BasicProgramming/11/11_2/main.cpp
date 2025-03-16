#include "Leaver/Leaver.h"
#include <iostream>

int main()
{
    Leaver my_leaver;

    std::string name;

    std::cout << "Enter  your name: ";
    std::cin >> name;
    std::cout << my_leaver.leave(name) << std::endl;

    return 0;
}