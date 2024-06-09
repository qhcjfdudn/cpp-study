#include <iostream>
#include <experimental/generator>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

std::experimental::generator<int> foo(int from, int to) {
	for (int num = from; num < to; ++num) {
		co_yield num;
	}
}

int main() {
	for (auto num : foo(1, 4)) {
		std::this_thread::sleep_for(1s);
		std::cout << num << std::endl;
	}
	// 1 2 3 차례로 출력 후 종료
}