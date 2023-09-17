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
using add_pointer_t = typename add_pointer<T>::type;	// typename이 없으면 type으로 보지 못한다.

template<typename T>
struct is_pointer {
	static const bool value = false;
};

template<typename T>
struct is_pointer<T*> {
	static const bool value = true;
};

//// 내가 생각한 구현
//template<typename T>
//const bool is_pointer_v = is_pointer<T>::value;

// 정의로 확인해본 실제 구현
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