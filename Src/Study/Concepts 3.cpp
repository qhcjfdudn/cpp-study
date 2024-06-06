#include <iostream>
#include <type_traits>

template<typename T>
concept NonPointer = !std::is_pointer_v<T>;

// template<NonPointer T>	// �̷��� �ص� �ǰ�
template<typename T> //requires NonPointer<T>	// �̷��� �ص� �ǰ�
void swap(T& a, T& b) requires NonPointer<T>	// �̷��� �ص� �ȴ�.
{
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
	swap(pa, pb);	// enable_if�� ������ ������� ���� 
	// SFINAE�� ���� ������ ����
	// ������ template�� �������� ��������..
	// �̰� concept�� �ؼ�!
	std::cout << a << " " << b << std::endl;
}