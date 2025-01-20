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

int main()
{
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