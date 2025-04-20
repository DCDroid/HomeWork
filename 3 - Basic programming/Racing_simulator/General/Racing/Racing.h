#pragma onсe

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
    std::list<Vehicle*> vehicleList; 
    bool available_vehicle[7];
    int racers_count{0};
    int length{0};
    
    // std::list<Vehicle> vehicleList; 
    
private:
    void add_vehicle_air(vehicle_type vehicle);
    void add_vehicle_ground(vehicle_type vehicle);
    void add_vehicle_general(vehicle_type vehicle);
    
public:
    void add_vehicle(vehicle_type vehicle);
    void set_air_type();
    void set_ground_type();
    void set_general_type();
    race_type get_type();
    std::list<Vehicle> get_vehicle_list();
    void set_length(int length);
    int get_distance();
    bool is_ready();
    void start_race();

    ~Racing();
};