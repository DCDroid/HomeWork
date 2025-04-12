#pragma onсe

#include "../General/Vehicle.h"

class Broom : public Vehicle
{
public:
    float get_time(int len);
    virtual ~Broom() = default;
};

class Eagle : public Vehicle
{
public:
    float get_time(int len);
    virtual ~Eagle() = default;
};

class AirplaneCarpet : public Vehicle
{
public:
    float get_time(int len);
    virtual ~AirplaneCarpet() = default;
};

