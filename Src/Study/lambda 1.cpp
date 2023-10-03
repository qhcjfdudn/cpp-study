	#include <iostream>
	#include <functional>

	using std::cout;
	using std::endl;

void foo(std::function<void(void)> func) {
	func();
}

int main() {
	// lambda의 기본형
	[]() -> int {	// return 타입 지정 가능.

	};

	// 파라미터가 없다면, 아래처럼 소괄호 생략 가능.
	[] {};

	// 캡쳐
	int v = 10;
	[v] {
		// [] 안에 변수를 담으면, 람다의 scope으로 전달 된다. 캡쳐한다고 함.
		cout << "v: " << v << endl;
	}();	// 중괄호 뒤에 ()를 넣으면 바로 실행.

	[](int value) {	// 캡쳐가 아닌 파라미터로 받을 수도 있음.
		cout << "value: " << value << endl;
	}(v);

	int value = 5;
	auto f1 = [](int v) {
		cout << "v: " << v << endl;
	};
	// foo(f1);	// error. foo의 함수는 파라미터가 없는 함수를 받아야 한다.

	auto f = [value]() {
		cout << "value: " << value << endl;
	};

	foo(f);	// 캡쳐를 통해 foo의 함수 전달 가능.

	[value] {	
		// value = 20; // 캡쳐로 전달되는 변수는 수정이 불가능하다.
	} ();
	cout << "value: " << value << endl;

	// 캡쳐로 전달하는 변수 값 수정하는 방법
	// 1. 캡쳐에 참조로 전달.
	[&value] {	// 캡쳐로 참조를 전달하면 값 수정 가능.
		value = 20;
	} ();
	cout << "value: " << value << endl;

	// 2. mutable
	[value] () mutable {
		value = 30;
		cout << "value: " << value << endl;
	} ();
}