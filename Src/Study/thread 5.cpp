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
				cv.wait(lock);		// notify 이후에 wait 코드 수행된다면
									// notify 받지 못하고 날릴 것. 그리고
									// jobQueue는 요소가 있을 것이다.
									// 그러면 queue에 요소가 있는 것이니
									// wait을 수행하지 말도록 하기 위한
									// 방어 코드이다.
			
			if (jobQueue.empty())	// spurious wakeup
				continue;			// notify 하지 않았는데 깨어날 수도 있다.
									// notify 되었느냐 아니느냐를 판단하지 못할 때가
									// 있는데, 그렇다면 만약 notify가 있다면 깨어나야
									// 하니까 판단을 못할 땐 깨우는 걸로 정했다.
									// 그래서 아래와 같은 방어 코드를 작성한다.

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