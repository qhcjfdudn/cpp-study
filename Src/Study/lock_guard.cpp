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
					// �Ʒ��� ���� ����� �������� �ؾ� �ǵ���� ����.
					// for�� �ȿ����� �ѹ� �� ����� ������ �ʾƵ� �ȴ�.
					// �� �Ʒ� ���� ����� ��� ���� ����.
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