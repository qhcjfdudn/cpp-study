#include <iostream>
#include <chrono>
#include <future>
#include <experimental/coroutine>

using namespace std::chrono_literals;

int long_time_job() {
	std::this_thread::sleep_for(1s);
	return 100;
}

std::future<int> c() {
	std::cout << "coroutine 0" << std::endl;

	// 아래 줄이 핵심이다. co_await와 async를 한다.
	// async의 반환은 원래 future 객체여야 하는데
	// co_await를 쓰면서 int를 반환한다.
	auto result = co_await std::async(long_time_job);
	std::cout << "coroutine 1" << std::endl;

	// result를 co_return으로 반환하면 future<int> 객체로 리턴하게 된다.
	co_return result;
}

int main() {
	auto future = c();
	std::cout << "main 0" << std::endl;

	std::cout << future.get() << std::endl;

	/*
	* 전체 출력 결과는 아래와 같다.
	* coroutine 0
	* main 0
	* coroutine 1 (1초 뒤에 수행)
	* 100
	*/
}