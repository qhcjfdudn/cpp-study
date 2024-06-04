#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::promise<int> pi;
	std::future<int> fu = pi.get_future();

	// promise 객체를 캡쳐로 넣지 않고 인자로 전달할 땐
	// 반드시 std::move(pi)를 해야 한다.
	// move를 하지 않고 인자로 전달하면 alert 발생.
	std::thread t1([&pi]()
		{
			std::this_thread::sleep_for(2s);
			pi.set_value(2);
		});
	//	}, std::move(pi));

	std::cout << fu.get() << std::endl;	// 2초 뒤에 2 출력

	t1.join();
}