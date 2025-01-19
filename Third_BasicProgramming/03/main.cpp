#include <iostream>

class Calculator
{
private:
    double m_num_1;
    double m_num_2;
public:
    bool set_num1(const double num1);
    bool set_num2(const double num2);
    double add();
    double multiply();
    double subtract_1_2();
    double subtract_2_1();
    double divide_1_2();
    double divide_2_1();
};

class Counter
{
private:
    int m_counter = 0;
public:
    Counter() = default;
    Counter(const int init_value)
    {
        m_counter = init_value;
    }
    void increment() { m_counter++; }
    void decrement() { m_counter--; }
    int get_counter() { return m_counter; }
};

int main()
{
    // FIRST BEGIN
    
    double num_1{}, num_2{};
    Calculator my_calculator;

    std::cout << "Enter num1: ";
    std::cin >> num_1;
    std::cout << "Enter num2: ";
    std::cin >> num_2;

    if (!(my_calculator.set_num1(num_1) && my_calculator.set_num2(num_2))) {
        std::cout << "Error\n";
        return 0;
    }

    std::cout << "num_1 + num_2 = " << my_calculator.add() << '\n';
    std::cout << "num_1 - num_2 = " << my_calculator.subtract_1_2() << '\n';
    std::cout << "num_2 - num_1 = " << my_calculator.subtract_2_1() << '\n';
    std::cout << "num_1 * num_2 = " << my_calculator.multiply() << '\n';
    std::cout << "num_1 / num_2 = " << my_calculator.divide_1_2() << '\n';
    std::cout << "num_2 / num_1 = " << my_calculator.divide_2_1() << '\n';
    
    // FIRST END
    

    // SECOND BEGIN
    /*
    std::string res{};
    char command{};

    std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
    std::cin >> res;

    if (res.compare("yes") != std::string::npos) {
        std::cout << "Enter the initial counter value: ";
        int init_value{};
        std::cin >> init_value;
        Counter my_counter(init_value);
        while (true)
        {
            std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
            std::cin >> command;
            if (command == '+') my_counter.increment();
            else if (command == '-') my_counter.decrement();
            else if (command == '=') std::cout << my_counter.get_counter() << std::endl;
            else if (command == 'x') break;
        }
    }
    else if (res.compare("no") != std::string::npos) {
        Counter my_counter;
        while (true)
        {
            std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
            std::cin >> command;
            if (command == '+') my_counter.increment();
            else if (command == '-') my_counter.decrement();
            else if (command == '=') std::cout << my_counter.get_counter() << std::endl;
            else if (command == 'x') break;
        }
    }
    // SECOND END
    */
}

bool Calculator::set_num1(const double num1)
{
    if (num1 != 0) {
        m_num_1 = num1;
        return true;
    }
    else return false;
}

bool Calculator::set_num2(const double num2) {
    if (num2 != 0) {
        m_num_2 = num2;
        return true;
    }
    else return false;
}

double Calculator::add() {
    return m_num_1 + m_num_2;
}

double Calculator::subtract_1_2() {
    return m_num_1 - m_num_2;
}

double Calculator::subtract_2_1() {
    return m_num_2 - m_num_1;
}

double Calculator::multiply() {
    return m_num_1 * m_num_2;
}

double Calculator::divide_1_2() {
    return m_num_1 / m_num_2;
}

double Calculator::divide_2_1() {
    return m_num_2 / m_num_1;
}