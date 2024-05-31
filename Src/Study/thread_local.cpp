#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
// thread local�� thread���� �����ϴ� ���� ����
// static���� ���̸� �����غ���.

// 1. thread�� ����� �� ������ �� �ִ� �ڵ带 ���� �� �ֵ�.
// �̷��� �ϴ� �ǹ̰� �����ΰ�?
struct Test
{
	int num;
	Test(int num) : num(num)
	{
		std::cout << "Construct : " << num << std::endl;
	}
	~Test() {
		std::cout << "Destruct : " << num << std::endl;
	}
};

// static���� thread_local keyword�� �ٿ���.
// ���� thread���� �����ϴ� ���� �޸� ���� ��. �׷��� test ��ü�� ��� �����ϳ�?
thread_local Test test(10);

// 2. static int�� �� �� ����� �ʱ�ȭ�� �̷������ �ٽ� �̷����� ������
// thread_local�� ���� thread���� �ʱ�ȭ�Ǿ� �����Ѵ�.
void foo() {
	for (int i = 0; i < 10; ++i) {
		static int sInt = 5;
		thread_local int tlInt = 5;
		sInt++;
		tlInt++;
		std::cout << "sInt: " << sInt << ", tlInt: " << tlInt << std::endl;
	}
}

int main() {
	foo();
	std::thread(foo).join();
}