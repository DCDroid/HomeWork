#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

template<typename T>
class SafeQueue {
public:
	SafeQueue();
	~SafeQueue();

	void push(T item);

	std::optional<T> pop();

	std::optional<T> try_pop();

	void shutdown();

	bool empty() const;

private:
	std::queue<T> queue_;
	mutable std::mutex mutex_;
	std::condition_variable cv_;
	bool shutdown_ = false;
};

