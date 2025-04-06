#include "Racing.h"

void Racing::add_vehicle_air() {

}

void Racing::add_vehicle_ground() {
    
}

void Racing::add_vehicle_general() {
    
}

//

void Racing::set_air_type() {
    this->add_vehicle = add_vehicle_air;
}

void Racing::set_ground_type() {
    this->add_vehicle = add_vehicle_ground;
}

void Racing::set_general_type() {
    this->add_vehicle = add_vehicle_general;
}

void Racing::set_length()
{

}
