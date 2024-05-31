#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

int main() {
	std::mutex m;
	int num = 0;

	auto func = [&num, &m]
		{
			for (int i = 0; i < 100000; ++i) {
				m.lock();
				num += 1;
				m.unlock();
			}
		};

	std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();

	std::cout << num << std::endl;
}