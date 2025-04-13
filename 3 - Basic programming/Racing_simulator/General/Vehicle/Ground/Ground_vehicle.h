#pragma onсe

#include "../General/Vehicle.h"

class OffRoadBoots : public Vehicle
{
public:
    float calculate_time(float len);
    float time_of_movement_before_rest;
    float rest_time_1;
    float rest_time_2;
    float rest_time_3;
    OffRoadBoots();
    virtual ~OffRoadBoots() = default;
};

class Camel : public Vehicle
{
public:
    float calculate_time(float len);
    float time_of_movement_before_rest;
    float rest_time_1;
    float rest_time_2;
    float rest_time_3;
    Camel();
    virtual ~Camel() = default;
};

class Centau : public Vehicle
{
public:
    float calculate_time(float len);
    float time_of_movement_before_rest;
    float rest_time_1;
    float rest_time_2;
    float rest_time_3;
    Centau();
    virtual ~Centau() = default;
};

class FastCamel : public Vehicle
{
public:
    float calculate_time(float len);
    float time_of_movement_before_rest;
    float rest_time_1;
    float rest_time_2;
    float rest_time_3;
    FastCamel();
    virtual ~FastCamel() = default;
};