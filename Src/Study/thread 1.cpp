#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main() {
	std::thread::id id = std::this_thread::get_id();
	std::cout << "main thread ID: " << id << std::endl;

	std::thread t1([] {
		std::thread::id id = std::this_thread::get_id();
		std::cout << "thread ID: " << id << std::endl;
		std::this_thread::sleep_for(1s);
		});

	auto start = std::chrono::system_clock::now();
	// t1.join();
	t1.detach();
	auto end = std::chrono::system_clock::now();

	auto calculatedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Complete. program time: " << calculatedTime.count() << std::endl;
}