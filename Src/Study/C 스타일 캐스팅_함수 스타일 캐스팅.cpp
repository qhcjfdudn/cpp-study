#include <iostream>

using std::cout;
using std::endl;

using ParentPointer = Parent*;

class Parent {
public:
	Parent() {}
	explicit Parent(int i) {}
};

int main() {
	Parent p = Parent(10);	// ������ ȣ��
	ParentPointer pp = ParentPointer(&p);	// ������ ȣ��ó�� ��������
											// ����ȯ
}