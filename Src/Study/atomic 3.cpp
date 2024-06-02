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

	// �� �޼��尡 true�� ���� atomic�� ������ ����. �װ� �ƴ϶��
	// ���� ����ȭ ��Ŀ������ ������ �Ѵ�.
	if (num.is_lock_free());
}