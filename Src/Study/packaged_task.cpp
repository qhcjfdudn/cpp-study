#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::packaged_task<int()> pt([]
		{
			std::this_thread::sleep_for(2s);
			return 1;
		});

	// pt();	pt를 2번 실행하게 되면 promise와 동일하게 런타임 에러 발생한다.

	std::future<int> ft = pt.get_future();
	std::thread t(std::move(pt));	// move를 해야 하기 때문에 반드시
									// 현재 스레드에서 이후에 pt 객체가
									// 참조되면 안된다. 런타임 에러 발생.

	std::cout << ft.get() << std::endl;

	t.join();
}