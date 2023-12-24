#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

std::atomic<int> n(0);

void f() {
    for (int i = 0; i < 1000000; ++i)
        // memory_order_relaxed: CPU�� �����Ӱ� �޸� ���� ���� ������
        // �����ص� �ȴٴ� �ǹ̸� ����. ������ ��������ó�� ������ ����ϴµ�
        // ������ thread �۾��� ������ ������ ����� ����Ǹ� �Ǵ� ���
        // CPU ����� ���ġ�ص� �ȴٸ� ������ ���� ���̴�.
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