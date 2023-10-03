#include <iostream>

using std::cout;
using std::endl;

struct Test {
	int num = 1;
	
	auto func() {
		int num = 3;
		return [&num]() {	// �޸𸮰� ������ ���
			return num;		// ������ �� ��ȯ�� �� �ִ�.
		};
	}

	auto func2() {
		return [num = num]() { // Initializer ĸ��. C++14���� ����
		// return [*this] { // C++17���� ����
		// return [a = 1, b = std::string()] { // �̷� �͵� ����
		// return [a = num * 20] // ���� �� ����..
			return num;
		};
	}
};

int main() {
	Test* t = new Test();
	auto f = t->func();
	delete t;

	cout << f() << endl;	// garbage �� ���
							// ĸ�Ŀ��� ������ �����ߴµ�
							// ������ �޸𸮰� �����Ǿ���
							// ����

							// ������ �ƴ� ������ �����ϸ�
							// ���������� ��ȯ

	t = new Test();
	auto f2 = t->func2();

	cout << f2() << endl;

}