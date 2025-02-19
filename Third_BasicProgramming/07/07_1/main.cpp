#include <iostream>

#define MODE 1

#ifndef MODE
#error Important macro required
#endif

#if MODE == 1

int add(int a, int b) {
    return (a + b);
}

#endif 

int main()
{

    #if MODE == 0
        std::cout << "Work in test mode" << std::endl;
    #elif MODE == 1
        int a{}, b{};
        std::cout << "Work in fighting/war mode" << std::endl;
        std::cout << "Enter first number: ";
        std::cin >> a;
        std::cout << "Enter second number: ";
        std::cin >> b;
        std::cout << "Add result: " << add(a, b) << '\n';
    #else
        std::cout << "Unknown mode. Shutdown\n";
    #endif          

    return 0;
}