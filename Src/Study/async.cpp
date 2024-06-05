#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

//	std::future<int> ft = std::async([](int value)	// �⺻��
//	std::future<int> ft = std::async(std::launch::async	// ���� �����ϴ�.
//		| std::launch::deferred, [](int value)
//	std::future<int> ft = std::async(std::launch::async, [](int value)	// �ϳ������ε� ���� ����
																		// �ٸ� thread���� ����
	std::future<int> ft = std::async(std::launch::deferred, [](int value)	// ���� thread���� ����
		{
			std::cout << "async thread ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(2s);
			return value + 10;
		}, 10);

	std::cout << ft.get() << std::endl;
}