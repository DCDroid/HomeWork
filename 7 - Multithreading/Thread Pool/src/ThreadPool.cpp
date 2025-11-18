#include "../include/ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(size_t threads)
{
    if (threads == 0) threads = 1;
    workers_.reserve(threads);
    for (size_t i = 0; i < threads; ++i) {
        workers_.emplace_back([this] { worker_loop(); });
    }
}

ThreadPool::~ThreadPool()
{
    shutdown();
}

void ThreadPool::submit(std::function<void()> task)
{
    if (stopping_.load()) return;
    tasks_.push(std::move(task));
}

void ThreadPool::shutdown()
{
    bool expected = false;
    if (!stopping_.compare_exchange_strong(expected, true)) {
        return;
    }
    tasks_.shutdown();
    for (auto &t : workers_) {
        if (t.joinable()) t.join();
    }
}

void ThreadPool::worker_loop()
{
    while (!stopping_.load()) {
        auto opt = tasks_.pop();
        if (!opt.has_value()) {
            break;
        }
        try {
            auto &task = *opt;
            task();
        } catch (const std::exception &e) {
            std::cerr << "ThreadPool task exception: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "ThreadPool task unknown exception" << std::endl;
        }
    }
}
