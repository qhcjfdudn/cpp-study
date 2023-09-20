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
	//	cout << Scoped::A << endl;	// error. �Ͻ��� ����ȯ �Ұ���.
	cout << static_cast<int>(Scoped::B) << endl;	// long long �ڷ����� �� �𸣰� int�� ĳ�����ϸ� ������ �� �� �ִ�.
	cout << static_cast<std::underlying_type_t<Scoped>>(Scoped::B) << endl;	// ���� ���

	// �׷��� ����� �������ϹǷ�, ��� ��ü�� ����ϰ� �ٲ㺸��.
	cout << Scoped::B << endl;

	// �׷��� Unscoped�� ���ؼ��� �������� �������� �Ѵ�.
	cout << Unscoped::A << endl;
}