#include <iostream>

struct address
{
    std::string m_town_name{};
    std::string m_strit_name{};
    int m_house_number{};
    int m_door_number{};
    int m_index{};
};

void print_address(address* address)
{
    std::cout << "Town: " << address->m_town_name << '\n';
    std::cout << "Strit: " << address->m_strit_name << '\n';
    std::cout << "House number: " << address->m_house_number << '\n';
    std::cout << "Door_number: " << address->m_door_number << '\n';
    std::cout << "Index: " << address->m_index << '\n';
}

int main()
{
    address first{"Omsk", "Lenina", 12, 56, 45669 };
    address second{"Tomsk", "Pushkina", 7, 45, 78225};

    print_address(&first);
    std::cout << '\n';
    print_address(&second);


    return 0;
}