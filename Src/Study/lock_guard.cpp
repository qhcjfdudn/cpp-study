#include <iostream>
#include <thread>
#include <mutex>

void foo(int num) {
	if (num > 5)
		throw "num over 5 exception";
}
int main() {
	std::mutex m;
	int num = 0;

	auto func = [&num, &m]
		{
			try {
				for (int i = 0; i < 100000; ++i) {
					// 아래와 같이 블록이 끝나도록 해야 의도대로 동작.
					// for문 안에서는 한번 더 블록을 만들지 않아도 된다.
					// 즉 아래 줄의 블록은 없어도 정상 동작.
					{
						std::lock_guard lg(m);
						num += 1;
						foo(num);
					}
				}
			}
			catch (const char* e) {
				std::cout << e << std::endl;
			}
		};

	std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();

	std::cout << num << std::endl;
}