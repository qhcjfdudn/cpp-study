#include <iostream>

using std::cout;
using std::endl;

class Func {
public:
	int value;
	void operator() () const {	// lambda�� �⺻�� �Լ��� ���޵Ǵ� this�� const�̴�.
		// value = 2; // error. this�� const�̱� ����.
 		cout << "value: " << value << endl;
	}
};

class Func2 {
public:
	int value;
	void operator() () {	// mutable�� ����� ��� const�� ����, ��� ������ �����ϴ�.
		value = 2;
		cout << "value: " << value << endl;
	}
};

int main() {
	int value = 10;
	auto func = [value]() {
		// value = 20; // ���� �Ұ���.
		cout << "value: " << value << endl;
	};

	// lambda�� ���� ������ �����̴�. ������ ������ �����̴�.
	Func func1;

	// ĸ�Ĵ� �Ʒ��� ����.
	func1.value = 20;

	func();
	func1();

	// ĸ���� ������ �����ϱ� ���� mutable ���
	auto func2 = [value]() mutable {
		value = 5;
		cout << "value: " << value << endl;
	};
	
	Func2 func3;
}