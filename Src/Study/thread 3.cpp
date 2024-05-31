#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// CPU 스위칭으로 thread간 load - store 과정에서 race condition 발생해 결과에 이상 발생
int num = 0;

int main() {
	std::thread t([] {
		for (int i = 0; i < 1000000; ++i)
			num += 1;
	});

	for (int i = 0; i < 1000000; ++i)
		num += 1;

	t.join();

	std::cout << num << std::endl;	// 1274339 출력할 때마다 결과는 다르다.
									// race condition 때문.
}