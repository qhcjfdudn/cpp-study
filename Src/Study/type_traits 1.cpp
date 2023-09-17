#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T>
struct is_pointer {
	static const bool value = false;
};

template<typename T>
struct is_pointer<T*> {
	static const bool value = true;
};

template<typename T>
void foo(T t) {	// 함수 내부에서 이것이 포인터인지 구분하기 위해 사용
	cout << is_pointer<T>::value << endl;
}

int main() {
	cout << std::boolalpha;

	cout << std::is_pointer<int>::value << endl;	// false
	cout << std::is_pointer<int*>::value << endl;	// true
	
	cout << is_pointer<int>::value << endl;			// false
	cout << is_pointer<int*>::value << endl;		// true

	int num = 1;
	int* pNum = &num;

	foo(num);										// false
	foo(pNum);										// true

}