#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0 >
void foo() {							// 쓰지 않을 타입이라면 식별자를 사용하지 않아도 됨.
	cout << "is_integral_v" << endl;	// 0의 할당은, enable_if의 동작으로 Substitution Failure를 유도하는 idiom
										// idiom 부분은 다른 형태로 쓰여도 무관하다.
}

template<typename T, typename std::enable_if<std::is_floating_point_v<T>, int>::type = 0>
void foo() {
	cout << "is_floating_point_v" << endl;
}

int main() {
	foo<int>();		// is_integral_v
	foo<float>();	// is_floating_point_v
	foo<double>();	// is_floating_point_v
}