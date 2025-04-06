#pragma onse

#include <iostream>
#include <functional>
#include <list>

#include "Headers.h"

enum race_type { air = 1, ground, general };

class Racing
{
private:
    race_type m_race_type;
    bool ready{false};
    std::list<Vehicle> vehicleList; 
    bool available_vehicle[7] = {true}; // Почему не работае заполнение 1 всего массива? 
    int racers_count{0};
    int lenght{0};
 
private:
    void add_vehicle_air(vehicle_type vehicle);
    void add_vehicle_ground(vehicle_type vehicle);
    void add_vehicle_general(vehicle_type vehicle);
    
public:
    // std::function<void(vehicle_type vehicle)> add_vehicle;
    void add_vehicle(vehicle_type vehicle);


    void set_air_type();
    void set_ground_type();
    void set_general_type();

    void set_length(int length);

    bool is_ready();

    void start_race();
};