#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void sum(std::vector<uint32_t>& a, std::vector<uint32_t>& b, std::vector<uint32_t>& result, uint32_t start_index, uint32_t end_index)
{
    for(uint32_t i = start_index; i < end_index; i++)
    {
        result[i] = a[i] + b[i];
    }
}

int main()
{
    std::cout << "Кол-во аппаратных вычисляторов: " << std::thread::hardware_concurrency() << std::endl;

    std::cout << "\t\t1000" << " \t\t" << "10000" << " \t\t" << "100000" << " \t\t" << "1000000" << std::endl;

    uint32_t vector_length = 100000;
    uint32_t threads_count = 1;

    for(threads_count = 1; threads_count <= 16; threads_count *= 2)
    {
        std::cout << threads_count << " поток  \t";
        for(vector_length = 1000; vector_length <= 1000000; vector_length *= 10)
        {
            std::vector<uint32_t> a(vector_length);
            std::vector<uint32_t> b(vector_length);
            std::vector<uint32_t> result(vector_length);
            
            std::vector<std::thread> threads;

            auto start = std::chrono::steady_clock::now();

            size_t delta = vector_length / threads_count;
            for (size_t i = 0; i < threads_count; ++i) {
                size_t start = i * delta;
                size_t end = (i + 1 == threads_count) ? vector_length : start + delta;
                threads.emplace_back(sum, std::ref(a), std::ref(b), std::ref(result), start, end);
            }

            for(auto& th : threads)
            {
                th.join();
            }

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            std::cout << duration.count() << " ms\t";
        }
        std::cout << std::endl;
    }


    return 0;
}