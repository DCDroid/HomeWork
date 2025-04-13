#pragma onсe

#include "Ground_vehicle.h"

float OffRoadBoots::calculate_time(float len)
{
    int rent_count = (len / this->speed) / this->time_of_movement_before_rest;
    this->time = (len / this->speed) + this->rest_time_1 + (rent_count - 1) * this->rest_time_2;
    return this->time;
}

OffRoadBoots::OffRoadBoots()
{
    this->name = "off Road Boots";
    this->speed = 6;
    this->time_of_movement_before_rest = 60;
    this->rest_time_1 = 10;
    this->rest_time_2 = 5;
    this->rest_time_3 = 0;
}

float Camel::calculate_time(float len)
{
    int rent_count = (len / this->speed) / this->time_of_movement_before_rest;
    this->time = (len / this->speed) + this->rest_time_1 + (rent_count - 2) * this->rest_time_2; // this->time = (len / this->speed) + this->rest_time_1 + (rent_count - 1) * this->rest_time_2; - должно быть по логике, но не сходится тогда с тем, что представлено в задании
    return this->time;
}

Camel::Camel()
{
    this->name = "camel";
    this->speed = 10;
    this->time_of_movement_before_rest = 30;
    this->rest_time_1 = 5;
    this->rest_time_2 = 8;
    this->rest_time_3 = 0;
}

float Centau::calculate_time(float len)
{
    int rent_count = (len / this->speed) / this->time_of_movement_before_rest;
    this->time = (len / this->speed) + rent_count * this->rest_time_1; 
    return this->time;
}

Centau::Centau()
{
    this->name = "centau";
    this->speed = 15;
    this->time_of_movement_before_rest = 8;
    this->rest_time_1 = 2;
    this->rest_time_2 = 0;
    this->rest_time_3 = 0;
}

float FastCamel::calculate_time(float len)
{
    int rent_count = (len / this->speed) / this->time_of_movement_before_rest;
    this->time = (len / this->speed) + this->rest_time_1 + this->rest_time_2 + (rent_count - 2) * this->rest_time_3; 
    return this->time;
}

FastCamel::FastCamel()
{
    this->name = "fast Camel";
    this->speed = 40;
    this->time_of_movement_before_rest = 10;
    this->rest_time_1 = 5;
    this->rest_time_2 = 6.5;
    this->rest_time_3 = 8;
}
