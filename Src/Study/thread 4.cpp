#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int value = 0;
bool b = true;

int main() {
	std::thread t1([]
		{
			value += 1;
			b = false;
		});

	std::thread t2([]
		{
			value += 1;
			while (b) {}
			std::cout << value << std::endl;
		});

	t1.join();
	std::cout << "t1.join()" << std::endl;
	t2.join();
}