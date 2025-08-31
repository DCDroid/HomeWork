#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector vector = {1, 1, 2, 5, 6, 1, 2, 4};

    std::cout << "[IN]: ";
    for(auto i : vector) std::cout << i << " ";

    std::sort(vector.begin(), vector.end(), [](auto a, auto b)
    {
        return a < b;
    });

    auto t = std::unique(vector.begin(), vector.end());
    vector.erase(t, vector.end());

    std::cout << "\n[OUT]: ";
    for(auto i : vector) std::cout << i << " ";
    std::cout << std::endl;


    return 0;
}