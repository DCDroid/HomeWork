#include <iostream>

#include "General/Racing/Racing.h"

void print_info(Racing *race_pointer)
{
    if(race_pointer->get_type() == race_type::ground)
    {
        std::cout << "Racing for ground vehicle. ";
    }
    else if(race_pointer->get_type() == race_type::air)
    {
        std::cout << "Racing for air vehicle. ";
    }
    else if(race_pointer->get_type() == race_type::general)
    {
        std::cout << "Racing for ground and air vehicle. ";
    }
    std::cout << "Distance: " << race_pointer->get_distance() << std::endl;
}

void print_vehicle_info(Racing *race_pointer)
{
    std::cout << "Registered vehicles: ";
    
    for(auto i : race_pointer->get_vehicle_list()) {
        std::cout << i.get_name() << ", ";
    }
    std::cout << "\b\b   \n";
}

void print_result(Racing *race_pointer)
{
    std::cout << "Result: " << std::endl;

    int poss = 1;

    for(auto i : race_pointer->get_vehicle_list()) {
        std::cout << poss << ". " << i.get_name() << " - " << i.get_time() << "\n";
    }
}

int main()
{
    while(true)
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
        std::cout << "Length: " << tmp_integer << std::endl;
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

                    std::system("clear");
                    print_result(&my_race);

                    break;
                }
            }

            std::system("clear");
            // info
            print_info(&my_race);
            print_vehicle_info(&my_race);

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

        std::cout << "Do you want more? \n1. New race \n2. Exit" << std::endl;
        std::cin >> tmp_integer;
        if(tmp_integer == 2) {
            break;
        }
        std::system("clear");
    }
    
    

    
    

    return 0;
}