#include <iostream>

using std::cout;
using std::endl;

int main() {
	// 캡쳐가 없는 람다는 함수 포인터에 할당 가능.
	void (*f)(int) = [](int) {};
	int num = 3;
	// void (*g)(int) = [num](int) {}; // error.
}