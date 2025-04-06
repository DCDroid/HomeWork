#pragma onse

#ifndef HEADERNAME_H // ПОЧЕМУ БЕЗ ЭТОГОТ НЕ РАБОТАЕТ?
#define HEADERNAME_H // ПОЧЕМУ БЕЗ ЭТОГОТ НЕ РАБОТАЕТ?

enum vehicle_type { offRoadBoots = 1, broom, camel, centaur, eagle, fastCamel, airplaneCarpet, registrationEnd};

class Vehicle
{
private:
    int speed;
    float time_of_movement_before_rest;
    float rest_time;
public:
    // Vehicle();
    // void set_distance(int distance);
    virtual float get_time(int len);
};

#endif // ПОЧЕМУ БЕЗ ЭТОГОТ НЕ РАБОТАЕТ?
