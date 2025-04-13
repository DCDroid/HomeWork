#include "Air_vehicle.h"


float Broom::calculate_time(float len)
{
    float k = int(len / 1000);
    time = ((1 - k / 100) * len) / this->speed;
    return time;
    return 0;
}

Broom::Broom()
{
    this->name = "broom";
    this->speed = 20;
}

float Eagle::calculate_time(float len)
{
    time = (0.94 * len) / this->speed;
    return time;
}

Eagle::Eagle()
{
    this->name = "eagle";
    this->speed = 8.0;
}

float AirplaneCarpet::calculate_time(float len)
{
    if(len < 1000)
    {
        time = (len / this->speed);
        return time;
    }
    else if(len >= 1000 && len < 5000)
    {
        time = (0.97 * len) / this->speed;
        return time;
    }
    else if(len >= 5000 && len < 10000)
    {
        time = (0.9 * len) / this->speed;
        return time;
    }
    else if(len >= 10000)
    {
        time = (0.95 * len) / this->speed;
        return time;
    }
    
}

AirplaneCarpet::AirplaneCarpet()
{
    this->name = "airplane Carpet";
    this->speed = 10.0;
}