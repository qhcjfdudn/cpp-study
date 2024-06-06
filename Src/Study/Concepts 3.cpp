#include <iostream>
#include <type_traits>

template<typename T>
concept NonPointer = !std::is_pointer_v<T>;

// template<NonPointer T>	// 이렇게 해도 되고
template<typename T> //requires NonPointer<T>	// 이렇게 해도 되고
void swap(T& a, T& b) requires NonPointer<T>	// 이렇게 해도 된다.
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
	swap(pa, pb);	// enable_if의 조건을 통과하지 못해 
	// SFINAE에 의한 컴파일 에러
	// 하지만 template이 가독성이 떨어진다..
	// 이걸 concept이 해소!
	std::cout << a << " " << b << std::endl;
}