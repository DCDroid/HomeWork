#include "math_fun.h"

float sum(float a, float b)
{
    return a + b;
}

float sub(float a, float b)
{
    return a - b;
}

float mul(float a, float b)
{
    return a * b;
}

float div(float a, float b)
{
    return a / b;
}

float power(float a, float b)
{
    float res{1};
    for(int i{}; i < b; ++i)
    {
        res *= a;
    }
    return res;
}