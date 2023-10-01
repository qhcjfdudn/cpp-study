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

// ���������� C++17������ �Ʒ� ������� ���� �����ϴ�.
template<typename T>
decltype(auto) getValue4(T& t) {
	return t.getValue();
}

int main() {
	int num0 = 10;
	auto num1 = num0;
	decltype(num0) num2 = 30;
	decltype(auto) num3 = 40;	// int

	// auto�� ������ ���� �� ������
	// decltype�� ������ �޴� ���� �̿��Ѵ�.
	int& num4 = num1;
	decltype(auto) num5 = num4;	// int&

	Wrapper0 w0{ 10 };
	Wrapper1 w1{ 20 };

	getValue1(w0); // ������ return�ؼ� ���� ����.
	// getValue1(w1) = 22.3f; // error. auto�� ���۷����� return�� �� ���� ����.

	cout << getValue1(w0) << endl;
	cout << getValue1(w1) << endl;

	getValue2(w1) = 22.3f;	// ����
	cout << getValue2(w1) << endl;
}