#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	static_assert(!std::is_pointer_v<T>, "pointer value can't be passed");
	// 그렇지만 함수 안으로 들어오기 이전에 정적으로 컴파일 에러를
	// 알려줄 순 없을까?
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
	swap(pa, pb);	// static_assert 에러 호출!
	std::cout <<  a << " " << b << std::endl;
}