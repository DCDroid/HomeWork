#pragma onсe

#include "../General/Vehicle.h"

class Broom : public Vehicle
{
public:
    float calculate_time(float len);
    Broom();
    virtual ~Broom() = default;
};

class Eagle : public Vehicle
{
public:
    float calculate_time(float len);
    Eagle();
    virtual ~Eagle() = default;
};

class AirplaneCarpet : public Vehicle
{
public:
    float calculate_time(float len);
    AirplaneCarpet();
    virtual ~AirplaneCarpet() = default;
};

