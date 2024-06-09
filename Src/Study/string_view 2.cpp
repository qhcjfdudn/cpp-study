#include <iostream>

// �Լ��� ���ڷ� ���޹��� ���ڿ��� �б⸸ �Ѵٸ�
// ������ �ּ��� �ڵ�� ?
void f1(std::string name) {}		// worst
// => name �� �ƴ϶�, ���ڿ� ��ü���� ����
void f2(const std::string& name) {}	// good, not best
// 
void f3(std::string_view name) {}	// best

int main()
{
	std::string s = "to be or not to be";

	// �̷��� ���� �޸�, �ӵ� ���ɿ��� ũ�� ���̰� ����.
	f2(s);
	f3(s);

	// �̷��� ����?
	f2("to be or not to be");	// �Լ����� ����ϴ� �ӽð�ü�� �����.
	// ��ü�� �����Ǵ� ������ ���������� �߻�.
	f3("to be or not to be");	// ��� �޸𸮸� �״�� ����Ų��.