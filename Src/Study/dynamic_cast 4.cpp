#include <iostream>

class Parent {};

class Child : public Parent {};

int main() {
	Parent* p = new Child();
//	Child* c = dynamic_cast<Child*>(p); Parent�� ���� Ŭ������ �ƴ϶� ������ ����
	Child* c = static_cast<Child*>(p);	// ��� ���迡�� up/down �����ϰ� �� �� �ִ�.
										// �ٸ� down casting�̾ ���� ��ü�� Parent Ÿ���̶��
										// ����� ����������.
										// static_cast�� down casting ����� �������� �ʴ�.
}