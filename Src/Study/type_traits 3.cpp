#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

enum Unscoped {
	A, B
};

enum class Scoped : long long {
	A, B = 5342341321
};

template<typename T>
struct is_scoped {
	static const bool value = std::is_enum_v<T> && !std::is_convertible_v<T, int>;
};

template<typename T>
const bool is_scoped_v = is_scoped<T>::value;

template<typename T, typename std::enable_if_t<is_scoped_v<T>, int> = 0>
std::ostream& operator<<(std::ostream& os, const T& value) {	// SFINAE
	cout << "is Scoped." << endl;
	using type = std::underlying_type_t<T>;
	cout << static_cast<type>(value);
	return cout;
}

int main() {
	//	cout << Scoped::A << endl;	// error. 암시적 형변환 불가능.
	cout << static_cast<int>(Scoped::B) << endl;	// long long 자료형인 줄 모르고 int로 캐스팅하면 문제가 될 수 있다.
	cout << static_cast<std::underlying_type_t<Scoped>>(Scoped::B) << endl;	// 정상 출력

	// 그러나 출력이 지저분하므로, 출력 자체를 깔끔하게 바꿔보자.
	cout << Scoped::B << endl;

	// 그런데 Unscoped에 대해서는 적용하지 않으려고 한다.
	cout << Unscoped::A << endl;
}