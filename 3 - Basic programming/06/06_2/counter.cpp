#include "counter.h"

Counter::Counter(const int init_value)
{
    m_counter = init_value;
}

void Counter::increment() { m_counter++; }
void Counter::decrement() { m_counter--; }
int Counter::get_counter() { return m_counter; }
