#include "../include/SafeQueue.h"
#include <functional>

template<typename T>
SafeQueue<T>::SafeQueue() = default;

template<typename T>
SafeQueue<T>::~SafeQueue() { shutdown(); }

template<typename T>
void SafeQueue<T>::push(T item) {
	{
		std::lock_guard<std::mutex> lk(mutex_);
		queue_.push(std::move(item));
	}
	cv_.notify_one();
}

template<typename T>
std::optional<T> SafeQueue<T>::pop() {
	std::unique_lock<std::mutex> lk(mutex_);
	cv_.wait(lk, [this] { return !queue_.empty() || shutdown_; });
	if (queue_.empty()) {
		return std::nullopt;
	}
	T val = std::move(queue_.front());
	queue_.pop();
	return val;
}

template<typename T>
std::optional<T> SafeQueue<T>::try_pop() {
	std::lock_guard<std::mutex> lk(mutex_);
	if (queue_.empty()) return std::nullopt;
	T val = std::move(queue_.front());
	queue_.pop();
	return val;
}

template<typename T>
void SafeQueue<T>::shutdown() {
	{
		std::lock_guard<std::mutex> lk(mutex_);
		shutdown_ = true;
	}
	cv_.notify_all();
}

template<typename T>
bool SafeQueue<T>::empty() const {
	std::lock_guard<std::mutex> lk(mutex_);
	return queue_.empty();
}

template class SafeQueue<std::function<void()>>;
