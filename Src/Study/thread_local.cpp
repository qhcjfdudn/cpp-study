#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
// thread local은 thread별로 존재하는 정적 공간
// static과의 차이를 이해해보자.

// 1. thread가 실행될 때 동작할 수 있는 코드를 만들 수 있따.
// 이렇게 하는 의미가 무엇인가?
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

// static마냥 thread_local keyword를 붙였다.
// 각각 thread마다 존재하는 정적 메모리 같은 것. 그런데 test 객체에 어떻게 접근하나?
thread_local Test test(10);

// 2. static int는 한 번 선언과 초기화가 이루어지면 다시 이뤄지지 않지만
// thread_local은 개별 thread마다 초기화되어 수행한다.
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