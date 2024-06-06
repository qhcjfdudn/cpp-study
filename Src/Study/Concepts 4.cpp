#include <iostream>
#include <type_traits>

enum class E {
	A, B, C
};

template<typename T>
struct is_scoped_enum {
	static const bool value = std::is_enum_v<T> && !std::is_convertible_v<T, int>;
};
template<typename T>
const bool is_scoped_enum_v = is_scoped_enum<T>::value;

// scoped enum에 대해서만 동작하도록 << 연산자 오버로딩 코드 만들기.
template<typename T, std::enable_if_t<is_scoped_enum_v<T>, int> = 0>
std::ostream& operator<< (std::ostream& os, const T& e) {
	return os << static_cast<std::underlying_type_t<T>>(e);
}

int main() {
	std::cout << E::B << std::endl;
}