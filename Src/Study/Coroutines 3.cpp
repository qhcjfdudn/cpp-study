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

	// �Ʒ� ���� �ٽ��̴�. co_await�� async�� �Ѵ�.
	// async�� ��ȯ�� ���� future ��ü���� �ϴµ�
	// co_await�� ���鼭 int�� ��ȯ�Ѵ�.
	auto result = co_await std::async(long_time_job);
	std::cout << "coroutine 1" << std::endl;

	// result�� co_return���� ��ȯ�ϸ� future<int> ��ü�� �����ϰ� �ȴ�.
	co_return result;
}

int main() {
	auto future = c();
	std::cout << "main 0" << std::endl;

	std::cout << future.get() << std::endl;

	/*
	* ��ü ��� ����� �Ʒ��� ����.
	* coroutine 0
	* main 0
	* coroutine 1 (1�� �ڿ� ����)
	* 100
	*/
}