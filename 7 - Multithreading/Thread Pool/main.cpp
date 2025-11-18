#include "SafeQueue.h"
#include "ThreadPool.h"

#include <iostream>

int main()
{
	size_t hw = std::thread::hardware_concurrency();
	if (hw == 0) hw = 2;
	ThreadPool pool(hw);

	auto make_task = [](const std::string &name, int iter) {
		return [name, iter]() {
			std::cout << "Task " << name << " start (iter=" << iter << ") on thread " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::cout << "Task " << name << " done  (iter=" << iter << ") on thread " << std::this_thread::get_id() << std::endl;
		};
	};

	for (int i = 0; i < 5; ++i) {
		pool.submit(make_task("A", i));
		pool.submit(make_task("B", i));
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));

	return 0;
}