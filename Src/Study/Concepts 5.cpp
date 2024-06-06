#include <iostream>
#include <type_traits>

enum class Scoped {
	A, B, C
};

enum UnScoped {
	A, B, C
};

template<typename T>
concept ScopedEnum = std::is_enum_v<T> && !std::is_convertible_v<T, int>;

// scoped enum에 대해서만 동작하도록 << 연산자 오버로딩 코드 만들기.
template<typename T> requires ScopedEnum<T>
std::ostream& operator<< (std::ostream& os, const T& e) {
	std::cout << "함수 호출" << std::endl;
	return os << static_cast<std::underlying_type_t<T>>(e);
}

int main() {
	std::cout << Scoped::B << std::endl;
	std::cout << UnScoped::A << std::endl;
}