#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::promise<int> pi;
	std::future<int> fu = pi.get_future();

	// promise ��ü�� ĸ�ķ� ���� �ʰ� ���ڷ� ������ ��
	// �ݵ�� std::move(pi)�� �ؾ� �Ѵ�.
	// move�� ���� �ʰ� ���ڷ� �����ϸ� alert �߻�.
	std::thread t1([&pi]()
		{
			std::this_thread::sleep_for(2s);
			pi.set_value(2);
		});
	//	}, std::move(pi));

	std::cout << fu.get() << std::endl;	// 2�� �ڿ� 2 ���

	t1.join();
}