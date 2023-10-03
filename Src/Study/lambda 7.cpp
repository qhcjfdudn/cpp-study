#include <iostream>
#include <functional>

using std::cout;
using std::endl;

int main() {
	// 1. auto로 받기
	auto f = []() {};
	cout << typeid(f).name() << endl; // class `int __cdecl main(void)'::`2'::<lambda_1>

	// 2. function<> 클래스로 받기
	std::function<void(void)> f = []() {};
}