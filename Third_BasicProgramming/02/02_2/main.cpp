#include <iostream>

struct account
{
    int m_number{};
    std::string m_name{};
    double m_money{};
};

void change_balanse(account* user, double money) {
    user->m_money = money;
}

int main()
{
    int number{};
    std::string name{};
    double money{};

    std::cout << "Enter account number: ";
    std::cin >> number;
    std::cout << "Enter user name: ";
    std::cin >> name;
    std::cout << "Enter balance: ";
    std::cin >> money;


    account andrey{ number, name, money };

    std::cout << "Enter new balance: ";
    std::cin >> money;
    change_balanse(&andrey, money);

    std::cout << andrey.m_number << std::endl;
    std::cout << andrey.m_name << std::endl;
    std::cout << andrey.m_money << std::endl;

    return 0;
}