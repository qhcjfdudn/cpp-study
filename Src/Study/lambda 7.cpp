#include <iostream>
#include <functional>

using std::cout;
using std::endl;

int main() {
	// 1. auto�� �ޱ�
	auto f = []() {};
	cout << typeid(f).name() << endl; // class `int __cdecl main(void)'::`2'::<lambda_1>

	// 2. function<> Ŭ������ �ޱ�
	std::function<void(void)> f = []() {};
}