#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	static_assert(!std::is_pointer_v<T>, "pointer value can't be passed");
	// �׷����� �Լ� ������ ������ ������ �������� ������ ������
	// �˷��� �� ������?
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main() {
	int a = 1, b = 2;
	int& ra = a;
	int& rb = b;

	swap(ra, rb);
	std::cout << a << " " << b << std::endl;
	
	int* pa = &a;
	int* pb = &b;
	swap(pa, pb);	// static_assert ���� ȣ��!
	std::cout <<  a << " " << b << std::endl;
}