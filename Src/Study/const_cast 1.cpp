#include <iostream>
using std::cout;
using std::endl;

void func(const int& i) {
	int& j = const_cast<int&>(i);
	j = 10;
}

int main() {
	int i = 0;
	func(i);			// ���ڰ� const�� ���� ����������
	cout << i << endl;	// ���� 10���� ��µȴ�.

	const int i1 = 0;
	func(i1);			// undefined behavior.
	cout << i1 << endl;	// �����Ϸ� ���� ��� ��µ���
						// �� �� ���� ��Ȳ
}