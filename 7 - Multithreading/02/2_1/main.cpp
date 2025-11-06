#include <iostream>
#include <thread>

#include <time.h>

#include <atomic>
#include <mutex>

std::mutex m;

class Okno
{
    // std::atomic<uint32_t> counter = 0; // Рассмотрел 2 варианта: либо мьютекс, либо атомарная переменная

    uint32_t counter = 0;
    uint32_t max_counter = 10;

public:
    void increment_counter();
    void decrement_counter();
};

void Okno::increment_counter()
{
    while(counter < max_counter) 
    {
        {
            std::lock_guard<std::mutex> grd(m);
            counter++;
        }
        std::cout << "Counter increnent: " << counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Okno::decrement_counter()
{
    while(counter > 0) 
    {
        {
            std::lock_guard<std::mutex> grd(m);
            counter--;
        }
        std::cout << "Counter decrement: " << counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}


int main()
{
    Okno okno;
    std::thread t1(&Okno::increment_counter, &okno);
    std::thread t2(&Okno::decrement_counter, &okno);

    t1.join();
    t2.join();

    return 0;
}