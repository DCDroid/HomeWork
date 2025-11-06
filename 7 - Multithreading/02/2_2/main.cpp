#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cstdint>

#include <mutex>
#include <atomic>

// std::mutex mtx;
std::atomic<uint32_t> count_of_ended_threads = 0;

struct thread_info
{
    uint32_t thread_number;
    std::thread::id thread_id;
    std::atomic<uint32_t> progress = 0;
    std::chrono::milliseconds duration{0};
};

struct Node
{
    thread_info m_info;
    void foo();
};

void Node::foo()
{
    m_info.thread_id = std::this_thread::get_id();

    auto t0 = std::chrono::steady_clock::now();

    for (int i = 0; i < 100; ++i) {
        uint32_t sleep_time = static_cast<uint32_t>(std::rand() % 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        m_info.progress = (i + 1) / 100.0 * 30;
    }

    count_of_ended_threads++;

    auto t1 = std::chrono::steady_clock::now();
    m_info.duration = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
}

void bar_generator(std::vector<Node> &nodes)
{
    while(count_of_ended_threads < nodes.size())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::system("clear");
        std::cout << "# \t id \t\t\t\t  Progress Bar \t\t\t    Time \n";
        for (const auto &n : nodes) {
            std::cout << n.m_info.thread_number << " \t " << n.m_info.thread_id << " \t "; 
            for(int i = 0; i < 30; ++i) {
                if(i < n.m_info.progress) {
                    std::cout << "#";
                } else {
                    std::cout << "-";
                }
            }

            if(n.m_info.progress >= 30) {
                std::cout << " \t " << n.m_info.duration.count() << " ms\n";
            } else {
                std::cout << " \t In Process\n";
            }
        }
        
    }
}

int main()
{
    const uint32_t thread_count = 4;

    std::vector<std::thread> threads;
    std::vector<Node> nodes(thread_count);

    for(uint32_t i = 0; i < thread_count; ++i)
    {
        nodes[i].m_info.thread_number = i;
        threads.emplace_back(&Node::foo, &nodes[i]);
    }

    std::thread bat_thread(bar_generator, std::ref(nodes));
    bat_thread.join();

    for(auto& t : threads)
    {
        t.join();
    }

    
    
    return 0;
}
