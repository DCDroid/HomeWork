#include <iostream>
#include <vector>
#include <algorithm>

class Counter 
{

private:
    int m_summ = 0;
    int m_count = 0;

public:
    void operator()(int number)
    {
        if(number % 3 == 0) 
        {
            m_summ += number;
            m_count++;
        }
    }

    int get_sum()
    {
        return m_summ;
    }

    int get_count()
    {
        return m_count;
    }
};

int main() 
{

    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;
    
    return 0;
}