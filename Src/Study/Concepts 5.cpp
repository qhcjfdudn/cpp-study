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

// scoped enum�� ���ؼ��� �����ϵ��� << ������ �����ε� �ڵ� �����.
template<typename T> requires ScopedEnum<T>
std::ostream& operator<< (std::ostream& os, const T& e) {
	std::cout << "�Լ� ȣ��" << std::endl;
	return os << static_cast<std::underlying_type_t<T>>(e);
}

int main() {
	std::cout << Scoped::B << std::endl;
	std::cout << UnScoped::A << std::endl;
}