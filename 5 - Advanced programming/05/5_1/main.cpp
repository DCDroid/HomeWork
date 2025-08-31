#include <iostream>
#include <vector>

template <class T>
T my_sqr(T a)
{ 
    return a * a;
}

template <class T> 
std::vector<T> my_sqr(std::vector<T>& vector)
{
    for(auto& i : vector)
    {
        i = i * i;
    }
    return vector;
}

int main()
{
    std::vector<int> my_vector = {-1, 2, 8};

    std::cout << my_sqr(4) << std::endl;

    my_sqr(my_vector);
    for(auto i : my_vector)
    {
        std::cout << i << std::endl;
    }
     
    return 0;
}

