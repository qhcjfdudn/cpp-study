#include <iostream>
#include <coroutine>
#include <chrono>
#include <future>
#include <experimental/coroutine>

using namespace std::chrono_literals;

std::experimental::coroutine_handle<> coro;

struct suspend {
	// 준비가 되면 true여야 하는데,
	// 이건 항상 false여서 always suspend 되는 것이다.
	int num = 1;
    bool await_ready() noexcept {
		++num;
		std::cout << num << std::endl;
        return num > 5;
    }

	// coroutine_handle 이녀석이 재개를 해준다.
    void await_suspend(std::experimental::coroutine_handle<> c) noexcept {
		std::cout << "await_suspend() num: " << num << std::endl;
		coro = c;
	}

    int await_resume() noexcept {
		std::cout << "await_resume() num: " << num << std::endl;
		return 123;
	}
};

std::future<int> c() {
	std::cout << 1 << std::endl;
	// co_await std::experimental::suspend_never();
	int result = co_await suspend();
	std::cout << 2 << std::endl;

	co_return result;
}

int main() {
	std::future<int> ft = c();

	std::cout << "ft.wait_for(2s)" << std::endl;
	
	while (true) {
		std::this_thread::sleep_for(1s);
	}
	std::cout << ft.get() << std::endl;
}