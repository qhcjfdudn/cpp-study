#include <iostream>
#include <string>

class Test {
public:
	Test() = default;
	explicit Test(const Test&) {}
	Test(const char*) {}	// 이게 explicit이면 "123"의 상수를 받을 수 없다.
	// string도 이렇게 구현돼 있을 것.
};

void func(const Test& t) {}

int main() {
	Test t;
	func(t);
	func("123");

	std::string str = "123";
}