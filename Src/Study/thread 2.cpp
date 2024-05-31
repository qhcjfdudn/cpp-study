#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main() {
	std::cout << "this_thread::get_id(): " << std::this_thread::get_id() << std::endl;

	std::thread t([] {
		std::cout << "this_thread::get_id(): " << std::this_thread::get_id() << std::endl;

		std::this_thread::sleep_for(1s);
		});
	t.join();
	if (t.joinable())
	{
		std::cout << "더이상 joinable하지 않기 때문에 호출되지 않을 것";
		t.join();
	}

	std::thread t2 = t;	// 복사 불가능
	std::thread t3 = std::move(t);	// move는 가능~
}