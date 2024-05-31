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
		std::cout << "���̻� joinable���� �ʱ� ������ ȣ����� ���� ��";
		t.join();
	}

	std::thread t2 = t;	// ���� �Ұ���
	std::thread t3 = std::move(t);	// move�� ����~
}