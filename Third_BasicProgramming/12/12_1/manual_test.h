#pragma once

#include "extended_array.h"
#include <cassert>
#include <sstream>

template <typename TestFunc>
void RunOneTest(TestFunc tfunc, const std::string& test_name) {
    try
    {
        tfunc();
        std::cerr << test_name << " OK" << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
}

template <typename T, typename U>
void AssertEq(const T& valueA, const U& valueB) {
    
    if (valueA != valueB) {
        std::ostringstream err;
        
        // Почему закомментированный код ниже выбрасывает ишибку при компиляции? 
        
        if constexpr (std::is_same_v<T, std::pair<int, int>>) {
            err << "For pair: (" << valueA.first << ", " << valueA.second << ") != (" << valueB.first << ", " << valueB.second << ")";
        } else if constexpr (std::is_same_v<U, std::pair<int, int>>) {
            err << "For pair: (" << valueA.first << ", " << valueA.second << ") != (" << valueB.first << ", " << valueB.second << ")";
        } else {
            err << "Assertion failed: " << valueA << " != " << valueB;
        }
        

        throw std::runtime_error(err.str());
    }
}

void test_mean() 
{
    ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    AssertEq(v1.mean(), 1.125);
}

void test_empty_mean() 
{
    ExtArray<int> v3{};
    AssertEq(v3.mean(), 0.0);
}

void test_median() 
{
    ExtArray<double> v2{ 4.5, 0.7, 10.8, 2.6, -3.5 };
    AssertEq(v2.median(), 2.6);
}

void test_empty_median()
{
    ExtArray<int> v3{};
    
    try
    {
        AssertEq(v3.mode(), 0.0); // Выдает SEGFAULT // Как поймать кроме как ловителем сигналов в мейне?
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}

void test_mode()
{
    ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
    AssertEq(v1.mode(), std::pair(5, 3));
}

void test_empty_mode() 
{
    ExtArray<int> v3{};
    try
    {
        AssertEq(v3.mode(), std::pair(0, 0)); // Выдает SEGFAULT // Как поймать кроме как ловителем сигналов в мейне?
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}
