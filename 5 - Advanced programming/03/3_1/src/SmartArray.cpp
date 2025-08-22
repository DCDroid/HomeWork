#pragma onse

#include "SmartArray.h"

SmartArray& operator=(const SmartArray& other) {
    delete[] m_array; // Free existing memory
    m_size = other.m_size;
    m_current_index = other.m_current_index;
    m_array = new int[m_size]; // Allocate new memory
    for (int i = 0; i < m_current_index; ++i) {
        m_array[i] = other.m_array[i]; // Copy elements
    }
    std::cout << "Assignment operator called" << std::endl;

    return *this;
}

SmartArray::SmartArray(int size) {
    m_size = size;
    m_array = new int[m_size];
}

SmartArray::~SmartArray() {
    delete[] m_array;
}   

int SmartArray::get_element(int value) {
    if (value < 0 || value >= m_size) {
        throw MyException();
    }
    return m_array[value];
}

void SmartArray::add_element(int value) {
    
    if(m_current_index == m_size) {
        throw "Array is full";
    }
    m_array[m_current_index] = value;
    m_current_index++;
}

