#pragma onse

#include <iostream>
#include <functional>
#include <list>

#include "../Vehicle/General/Vehicle.h"

enum race_type { air = 1, ground, general };

class Racing
{
private:
    race_type m_race_type;

private:
    void static add_vehicle_air();
    void static add_vehicle_ground();
    void static add_vehicle_general();
    
public:
    std::function<void()> add_vehicle;
    std::list<Vehicle> vehicle_list;

    void set_air_type();
    void set_ground_type();
    void set_general_type();
};