#include <iostream>

template<typename T>
void foo(T t) {}

//auto bar() {
//	return { 1, 2 };	// �߰�ȣ�� ���� ����� ��ȯ ������ �������� ����
//}

template<typename T>
auto bar(T t) {
	return { 1, 2 };	// error C2440: 'return': 'initializer list'���� 'auto'(��)�� ��ȯ�� �� �����ϴ�.
}

int main() {
	int num(10);
	int num1{ 10 };

	auto num2(10);
	auto num3{ 10 };

	auto nums = { 1, 2 };	// std::initializer_list<int>

	// foo({ 1, 2 }); // ������ ����.
	bar(1);	// error C2440
}