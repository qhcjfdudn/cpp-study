#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main() {
	std::packaged_task<int()> pt([]
		{
			std::this_thread::sleep_for(2s);
			return 1;
		});

	// pt();	pt�� 2�� �����ϰ� �Ǹ� promise�� �����ϰ� ��Ÿ�� ���� �߻��Ѵ�.

	std::future<int> ft = pt.get_future();
	std::thread t(std::move(pt));	// move�� �ؾ� �ϱ� ������ �ݵ��
									// ���� �����忡�� ���Ŀ� pt ��ü��
									// �����Ǹ� �ȵȴ�. ��Ÿ�� ���� �߻�.

	std::cout << ft.get() << std::endl;

	t.join();
}