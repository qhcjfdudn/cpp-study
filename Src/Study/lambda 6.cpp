#include <iostream>

using std::cout;
using std::endl;

int main() {
	// ĸ�İ� ���� ���ٴ� �Լ� �����Ϳ� �Ҵ� ����.
	void (*f)(int) = [](int) {};
	int num = 3;
	// void (*g)(int) = [num](int) {}; // error.
}