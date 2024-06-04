#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>

using namespace std::chrono_literals;

void produce(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
	while (true) {
		{
			std::unique_lock lock(m);

			jobQueue.push(1);

			std::cout << "push. size: " << jobQueue.size() << std::endl;

			cv.notify_one();
			
			std::this_thread::sleep_for(1s);
		}

		std::this_thread::sleep_for(100ms);
	}
}

void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
	while (true) {
		{
			std::unique_lock lock(m);

			if (jobQueue.empty())	// lost wakeup
				cv.wait(lock);		// notify ���Ŀ� wait �ڵ� ����ȴٸ�
									// notify ���� ���ϰ� ���� ��. �׸���
									// jobQueue�� ��Ұ� ���� ���̴�.
									// �׷��� queue�� ��Ұ� �ִ� ���̴�
									// wait�� �������� ������ �ϱ� ����
									// ��� �ڵ��̴�.
			
			if (jobQueue.empty())	// spurious wakeup
				continue;			// notify ���� �ʾҴµ� ��� ���� �ִ�.
									// notify �Ǿ����� �ƴϴ��ĸ� �Ǵ����� ���� ����
									// �ִµ�, �׷��ٸ� ���� notify�� �ִٸ� �����
									// �ϴϱ� �Ǵ��� ���� �� ����� �ɷ� ���ߴ�.
									// �׷��� �Ʒ��� ���� ��� �ڵ带 �ۼ��Ѵ�.

			int num = jobQueue.front();
			jobQueue.pop();

			std::cout << "pop. size: " << jobQueue.size() << std::endl;
		}

		std::this_thread::sleep_for(50ms);
	}
}

int main() {
	std::mutex m;
	std::condition_variable cv;
	std::queue<int> jobQueue;
	std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue));
	std::thread consumer(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));

	producer.join();
	consumer.join();
}