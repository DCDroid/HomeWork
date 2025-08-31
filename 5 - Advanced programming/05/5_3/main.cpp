#include <iostream>
#include <vector>

class simple_functor {
    int m_summ;
    int m_count;
public:
    simple_functor():
    m_summ(0),
    m_count(0)
    {}

    int get_sum(std::vector<int>& input_numbers)
    {
        for(auto i : input_numbers)
        {
            if(i % 3 == 0) 
            {
                m_summ += i;
            }
        }
        return m_summ;
    }

    int get_count(std::vector<int>& input_numbers)
    {
        for(auto i : input_numbers)
        {
            if(i % 3 == 0) 
            {
                m_count++;
            }
        }
        return m_count;
    }
};

int main() 
{
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};
    simple_functor sf;
    
    std::cout << sf.get_sum(numbers) << std::endl;
    std::cout << sf.get_count(numbers) << std::endl;
    
    return 0;
}