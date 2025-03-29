#include <iostream>
#include "counter.h"

int main()
{
    std::string res{};
    char command{};

    Counter* _c = nullptr;

    std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
    std::cin >> res;

    if (res == "yes") {
        std::cout << "Enter the initial counter value: ";
        int init_value{};
        std::cin >> init_value;
        _c = new Counter(init_value);
    }
    else if (res == "no") {
        _c = new Counter();
    }
    else {
        std::cout << "You can use only yes or no";
        return 0;
    }
    while (true)
    {
        std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
        std::cin >> command;
        if (command == '+') _c->increment();
        else if (command == '-') _c->decrement();
        else if (command == '=') std::cout << _c->get_counter() << std::endl;
        else if (command == 'x') break;
    }
    delete _c;
}