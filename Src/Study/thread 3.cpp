#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// CPU ����Ī���� thread�� load - store �������� race condition �߻��� ����� �̻� �߻�
int num = 0;

int main() {
	std::thread t([] {
		for (int i = 0; i < 1000000; ++i)
			num += 1;
	});

	for (int i = 0; i < 1000000; ++i)
		num += 1;

	t.join();

	std::cout << num << std::endl;	// 1274339 ����� ������ ����� �ٸ���.
									// race condition ����.
}