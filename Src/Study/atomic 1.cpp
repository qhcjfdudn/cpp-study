#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

std::atomic<int> n(0);

void f() {
    for (int i = 0; i < 1000000; ++i)
        // memory_order_relaxed: CPU가 자유롭게 메모리 연산 동작 순서를
        // 변경해도 된다는 의미를 전달. 지금의 증감연산처럼 변수를 계산하는데
        // 동일한 thread 작업의 순서가 섞여도 결과만 보장되면 되는 경우
        // CPU 맘대로 재배치해도 된다면 성능이 빠를 것이다.
        n.fetch_add(1, std::memory_order_relaxed);
}

int main() {
    std::vector<std::thread> threads;
    threads.push_back(std::thread(f));
    threads.push_back(std::thread(f));

    for (int i = 0, len = static_cast<int>(threads.size()); i < len; ++i) {
        threads[i].join();
    }
    std::cout << n << std::endl;
}