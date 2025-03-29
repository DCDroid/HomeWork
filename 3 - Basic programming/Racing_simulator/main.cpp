#include <iostream>

#include "General/Racing/Racing.h"

int main()
{
    Racing my_race;

    int tmp_integer = 0;

    std::cout << "Welcome to racing simulator!\n1. Racing for ground vehicle\n2. Racing for air vehicle\n3. Racing for ground and air vehicle\nEnter racing type: " << std::endl;
    std::cin >> tmp_integer;

    switch (static_cast<race_type>(tmp_integer))
    {
    case ground:
        my_race.set_air_type();
        break;
    case air:
        my_race.set_ground_type();
        break;
    case general:
        my_race.set_general_type();
        break;
    default:
        break;
    }

    std::system("clear");
    std::cout << "Enter distance length(should be positive): " << std::endl;
    std::cin >> tmp_integer;

    

    
    

    return 0;
}