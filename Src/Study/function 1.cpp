#include <iostream>
#include <functional>

// function ��ü�� �Լ��� �Ҵ��ϴ� �����.

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
	// �Լ�
	std::function<int(float)> f = foo;
	std::cout << f(1.2f) << std::endl; // 1

	// ����
	f = [](float f) { return f; };
	std::cout << f(2.3f) << std::endl; // 2

	// �Լ� ��ü
	f = C();	// C Class�� �Լ� ��ü�� ����. operator()�� ���ǵǾ� �־�߸� ����.
	std::cout << f(3.4f) << std::endl; // 3

	// static �Լ�
	f = C::staticFunc;
	std::cout << f(4.5f) << std::endl; // 4

	// ��� �Լ�
	f = std::bind(&C::memberFunc, C(), std::placeholders::_1);
	std::cout << f(5.6f) << std::endl;	// 5
}