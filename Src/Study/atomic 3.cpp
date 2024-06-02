#include <iostream>
#include <thread>
#include <atomic>

int main() {
	std::atomic_int num = 0;

	std::thread t1([&num]
		{
			for (int i = 0; i < 1000000; ++i)
				num++;
		});

	std::thread t2([&num]
		{
			for (int i = 0; i < 1000000; ++i)
				num++;
		});

	t1.join();
	t2.join();

	std::cout << num << std::endl;	// 2000000

	// 이 메서드가 true일 때에 atomic한 연산이 가능. 그게 아니라면
	// 따로 동기화 매커니즘을 만들어야 한다.
	if (num.is_lock_free());
}