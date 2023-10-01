#include <iostream>

using std::cout;
using std::endl;

struct Wrapper0 {
	int value;
	int getValue() const {
		return value;
	}
};

struct Wrapper1 {
	float value;
	float& getValue() {
		return value;
	}
};

template<typename T>
auto getValue1(T& t) {
	return t.getValue();
}

template<typename T>
auto getValue2(T& t) -> decltype(t.getValue()) {
	return t.getValue();
}

template<typename T>
auto getValue3(T& t) -> decltype(auto) {
	return t.getValue();
}

// 최종적으로 C++17에서는 아래 모양으로 선언 가능하다.
template<typename T>
decltype(auto) getValue4(T& t) {
	return t.getValue();
}

int main() {
	int num0 = 10;
	auto num1 = num0;
	decltype(num0) num2 = 30;
	decltype(auto) num3 = 40;	// int

	// auto는 참조를 받을 수 없지만
	// decltype은 참조를 받는 점을 이용한다.
	int& num4 = num1;
	decltype(auto) num5 = num4;	// int&

	Wrapper0 w0{ 10 };
	Wrapper1 w1{ 20 };

	getValue1(w0); // 값으로 return해서 문제 없다.
	// getValue1(w1) = 22.3f; // error. auto는 레퍼런스를 return할 수 없기 때문.

	cout << getValue1(w0) << endl;
	cout << getValue1(w1) << endl;

	getValue2(w1) = 22.3f;	// 가능
	cout << getValue2(w1) << endl;
}