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
    // info
    std::cout << "Enter distance length(should be positive): " << std::endl;
    std::cin >> tmp_integer;
    my_race.set_length(tmp_integer);

    while (true)
    {
        std::system("clear");
        if(my_race.is_ready() == false) {
            std::cout << "At least 2 vehicles must be registered \n1. Register a vehicle \nEnter action: " << std::endl;
            std::cin >> tmp_integer; // nothing :)
        }
        else {
            std::cout << "1. Register a vehicle \n2. Start racing \nEnter action: " << std::endl;
            std::cin >> tmp_integer;
            if(tmp_integer == 2) {
                my_race.start_race();

                // print result

                break;
            }
        }

        std::system("clear");
        // info
        std::cout << "1. Off road boots\n2. Broom\n3. Camel\n4. Centau\n5. Eagle\n6. Fast camel\n7. Airplane carpet\n0. Registration end\nEnter vehicle or 0 for quit from registration: " << std::endl;
        std::cin >> tmp_integer;
        try
        {
            my_race.add_vehicle(static_cast<vehicle_type>(tmp_integer));
        }
        catch(std::string eText)
        {
            std::cout << eText << '\n';
        }
    }   
    
    

    
    

    return 0;
}