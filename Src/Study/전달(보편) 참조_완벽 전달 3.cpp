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
	goo(std::move(v));	// 컴파일 완료된 타입을 받아서, 무조건 rvalue로 바꾼다.

	goo(static_cast<T&&>(v));	// 전달 참조에 의해 lvalue/rvalue reference로 cast 된다.
	goo(std::forward<T>(v));	// 그걸 구현한 forward() 함수.
}

int main() {
	int num = 10;
					//	move	static_cast<T&&>	forward<T>
	foo(num);		//	int&&	int&				int&
	foo(10);		//	int&&	int&&				int&&
}