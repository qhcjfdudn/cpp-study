#include <iostream>
using std::cout;
using std::endl;

void func(const int& i) {
	int& j = const_cast<int&>(i);
	j = 10;
}

int main() {
	int i = 0;
	func(i);			// �Լ��� �ñ״��ĸ� ����
						// const�� ���� ���� ���̶� ���� �� ������ 
						// �ȵ� �Ŷ� �����Ѵٸ� ū��.
	cout << i << endl;	// ���� 10���� ��µȴ�.

	const int i1 = 0;	// undefined behavior.
	func(i1);			// �����Ϸ� ���� ��� ��µ���
	cout << i1 << endl;	// �� �� ���� ��Ȳ.
						
}