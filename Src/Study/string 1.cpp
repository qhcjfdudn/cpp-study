#include <iostream>
#include <string>

class Test {
public:
	Test() = default;
	explicit Test(const Test&) {}
	Test(const char*) {}	// �̰� explicit�̸� "123"�� ����� ���� �� ����.
	// string�� �̷��� ������ ���� ��.
};

void func(const Test& t) {}

int main() {
	Test t;
	func(t);
	func("123");

	std::string str = "123";
}