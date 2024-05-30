#include <iostream>
#include <functional>

// function 객체에 함수를 할당하는 방법들.

int foo(float f)
{
	return f;
}

class C {
public:
	int operator()(float f) {
		return f;
	}
	static int staticFunc(float f) {
		return f;
	}
	int memberFunc(float f) {
		return f;
	}
};

int main() {
	// 함수
	std::function<int(float)> f = foo;
	std::cout << f(1.2f) << std::endl; // 1

	// 람다
	f = [](float f) { return f; };
	std::cout << f(2.3f) << std::endl; // 2

	// 함수 객체
	f = C();	// C Class의 함수 객체를 대입. operator()가 정의되어 있어야만 가능.
	std::cout << f(3.4f) << std::endl; // 3

	// static 함수
	f = C::staticFunc;
	std::cout << f(4.5f) << std::endl; // 4

	// 멤버 함수
	f = std::bind(&C::memberFunc, C(), std::placeholders::_1);
	std::cout << f(5.6f) << std::endl;	// 5
}