	#include <iostream>
	#include <functional>

	using std::cout;
	using std::endl;

void foo(std::function<void(void)> func) {
	func();
}

int main() {
	// lambda�� �⺻��
	[]() -> int {	// return Ÿ�� ���� ����.

	};

	// �Ķ���Ͱ� ���ٸ�, �Ʒ�ó�� �Ұ�ȣ ���� ����.
	[] {};

	// ĸ��
	int v = 10;
	[v] {
		// [] �ȿ� ������ ������, ������ scope���� ���� �ȴ�. ĸ���Ѵٰ� ��.
		cout << "v: " << v << endl;
	}();	// �߰�ȣ �ڿ� ()�� ������ �ٷ� ����.

	[](int value) {	// ĸ�İ� �ƴ� �Ķ���ͷ� ���� ���� ����.
		cout << "value: " << value << endl;
	}(v);

	int value = 5;
	auto f1 = [](int v) {
		cout << "v: " << v << endl;
	};
	// foo(f1);	// error. foo�� �Լ��� �Ķ���Ͱ� ���� �Լ��� �޾ƾ� �Ѵ�.

	auto f = [value]() {
		cout << "value: " << value << endl;
	};

	foo(f);	// ĸ�ĸ� ���� foo�� �Լ� ���� ����.

	[value] {	
		// value = 20; // ĸ�ķ� ���޵Ǵ� ������ ������ �Ұ����ϴ�.
	} ();
	cout << "value: " << value << endl;

	// ĸ�ķ� �����ϴ� ���� �� �����ϴ� ���
	// 1. ĸ�Ŀ� ������ ����.
	[&value] {	// ĸ�ķ� ������ �����ϸ� �� ���� ����.
		value = 20;
	} ();
	cout << "value: " << value << endl;

	// 2. mutable
	[value] () mutable {
		value = 30;
		cout << "value: " << value << endl;
	} ();
}