#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

//	std::future<int> ft = std::async([](int value)	// 기본형
//	std::future<int> ft = std::async(std::launch::async	// 위와 동일하다.
//		| std::launch::deferred, [](int value)
//	std::future<int> ft = std::async(std::launch::async, [](int value)	// 하나만으로도 지정 가능
																		// 다른 thread에서 수행
	std::future<int> ft = std::async(std::launch::deferred, [](int value)	// 동일 thread에서 수행
		{
			std::cout << "async thread ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(2s);
			return value + 10;
		}, 10);

	std::cout << ft.get() << std::endl;
}