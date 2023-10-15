#include <iostream>
#include <utility>

using std::cout;
using std::endl;

void goo(int& v) {
	cout << "int&" << endl;
}
void goo(int&& v) {
	cout << "int&&" << endl;
}

template<typename T>
void foo(T&& v) {
	goo(std::move(v));	// ������ �Ϸ�� Ÿ���� �޾Ƽ�, ������ rvalue�� �ٲ۴�.

	goo(static_cast<T&&>(v));	// ���� ������ ���� lvalue/rvalue reference�� cast �ȴ�.
	goo(std::forward<T>(v));	// �װ� ������ forward() �Լ�.
}

int main() {
	int num = 10;
					//	move	static_cast<T&&>	forward<T>
	foo(num);		//	int&&	int&				int&
	foo(10);		//	int&&	int&&				int&&
}