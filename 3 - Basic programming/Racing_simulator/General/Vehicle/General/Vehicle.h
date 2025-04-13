#pragma once

#include <string>

enum vehicle_type { offRoadBoots = 1, broom, camel, centaur, eagle, fastCamel, airplaneCarpet, registrationEnd};

class Vehicle
{
protected:
    float speed;
    float time;
    std::string name;
public:
    virtual float calculate_time(float len);
    std::string get_name();
    float get_time() { return this->time; }
};