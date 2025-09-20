#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;
    int v_size = 0;
    int tmp_value = 0;
    std::cout << "[IN]: " << std::endl;
    std::cin >> v_size;

    while(v_size > 0) {
        std::cin >> tmp_value;
        v.push_back(tmp_value);
        v_size--;
    }

    std::sort(v.begin(), v.end(), [](int a, int b)
    {
        return a > b;
    });

    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::cout << "[OUT]: " << std::endl;
    for (int x : v)
        std::cout << x << std::endl;
}