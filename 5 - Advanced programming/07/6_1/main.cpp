#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    std::string input_string = "Hello world!!";
    std::map<char, int> counter_map;

    for(auto i : input_string) {
        auto nod = counter_map.find(i);
        if(nod == counter_map.end())
        {
            counter_map.insert({i, 1});
        }
        else
        {
            nod->second++;
        }
    }

    std::vector<std::pair<char, int>> vec(counter_map.begin(), counter_map.end());

    std::sort(vec.begin(), vec.end(), []( auto a,  auto& b) {
        return a.second > b.second;
    });

    for(auto i : vec) 
    {
        std::cout << (char)i.first << ": " << i.second << std::endl;
    }

    return 0;
}