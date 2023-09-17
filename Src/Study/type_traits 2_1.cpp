#include <iostream>

using std::cout;
using std::endl;

template<typename T>
struct add_pointer {
	using type = T*;
};

template<typename T>
struct add_pointer<T&> {
	using type = T*;
};

template<typename T>
using add_pointer_t = typename add_pointer<T>::type;	// typename�� ������ type���� ���� ���Ѵ�.

template<typename T>
struct is_pointer {
	static const bool value = false;
};

template<typename T>
struct is_pointer<T*> {
	static const bool value = true;
};

//// ���� ������ ����
//template<typename T>
//const bool is_pointer_v = is_pointer<T>::value;

// ���Ƿ� Ȯ���غ� ���� ����
template<typename T>
const bool is_pointer_v = false;

template<typename T>
const bool is_pointer_v<T*> = true;

int main() {
	cout << typeid(add_pointer_t<int>).name() << endl;

	cout << std::boolalpha;
	cout << is_pointer_v<int> << endl;
	cout << is_pointer_v<int*> << endl;
}