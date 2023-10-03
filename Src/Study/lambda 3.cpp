#include <iostream>

using std::cout;
using std::endl;

int main() {
	int count = 4;
	auto f = [count]() mutable {
		return ++count;
	};

	// �Լ��� ��縸 ����, ĸ���� ������ ������ �ʾƼ�
	// ��� ����� �� ���� ������ ����ȴ�. -> �Ǽ��� �߻��� �� �ִ�.
	// �׷��� default�� const�� ĸ�ĸ� ������ �� ���� ���·� �������.
	cout << f() << endl;	// 5
	cout << f() << endl;	// 6
	cout << f() << endl;	// 7
}