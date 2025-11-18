#pragma once

#include "SafeQueue.h"
#include <vector>
#include <thread>
#include <functional>
#include <atomic>
#include <memory>

class ThreadPool {
public:
	ThreadPool(size_t threads = std::thread::hardware_concurrency());
	~ThreadPool();

	void submit(std::function<void()> task);

	void shutdown();

private:
	void worker_loop();

	std::vector<std::thread> workers_;
	SafeQueue<std::function<void()>> tasks_;
	std::atomic<bool> stopping_{false};
};

