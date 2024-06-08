#include <iostream>
#include <type_traits>

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void swap_moved(T& a, T& b) {
	// 만약 pointer가 전달된다면
	// is_pointer_v<T>로 비교시 true가 된다.
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

template<typename T>
void swap_moved(T* a, T* b) {
	// 이렇게 포인터가 전달되는 건 단지 오버로딩이다.
	// 이 경우 T는 is_pointer_v로 비교시 fasle이다.
	T temp = *a;
	*a = *b;
	*b = temp;
}

class Test {
public:
	int num;
	Test() : num(0) {
		std::cout << "Test()" << std::endl;
	}
	explicit Test(int num) : num(num) {
		std::cout << "Test(num)" << std::endl;
	}
	Test(const Test& other) {
		std::cout << "const Test&" << std::endl;
		num = other.num;
	}
	Test(Test&& other) {
		std::cout << "Test&&" << std::endl;
		num = other.num;
	}
	Test& operator= (const Test& other) {
		std::cout << "operator= const Test&" << std::endl;
		num = other.num;
		return *this;
	}
	Test& operator= (Test&& other) noexcept {
		std::cout << "operator= Test&&" << std::endl;
		num = other.num;
		return *this;
	}
};

int main() {
	Test a{ 1 };	// Test(num)
	Test b{ 2 };	// Test(num)

	std::cout << a.num << " " << b.num << std::endl;	// 1 2
	swap(a, b);	// const Test&
	// operator= const Test&
	// operator= const Test&
	std::cout << a.num << " " << b.num << std::endl;	// 2 1
	swap_moved(a, b);	// Test&&
	// operator= Test &&
	// operator= Test &&
	std::cout << a.num << " " << b.num << std::endl;	// 1 2

	Test* pa = &a;
	Test* pb = &b;
	swap_moved(pa, pb);	// const Test&
	// operator= const Test&
	// operator= const Test&
	std::cout << a.num << " " << b.num << std::endl;	// 2 1
}