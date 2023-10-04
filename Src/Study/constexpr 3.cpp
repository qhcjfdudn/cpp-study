#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template <typename T>
auto getValue(T t) {
	if constexpr (std::is_pointer<T>())
	// if constexpr (std::is_pointer_v<T>)
		return *t;
	else return t;
}

int main() {
	int num = 3;
	int* pNum = &num;

	cout << getValue(num) << endl;
	cout << getValue(pNum) << endl;
}