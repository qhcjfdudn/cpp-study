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

template <typename T>
auto getValue2(T t) {
	if constexpr (std::is_pointer_v<T>)
	// if (std::is_pointer_v<T>)	// 컴파일 error.
	//	getValue2에 전달되는 타입이 int 같은 게 올 경우
	// *t 처럼 디레퍼런싱 해서 값을 참조할 수 없어서
	// 컴파일 에러가 발생한다.
	// 그런데 if constexpr의 경우에는 컴파일 시
	// 현재의 if 조건에 따라 디레퍼런싱 코드가 사라지므로
	// 정상적으로 컴파일이 된다.
		cout << *t << endl;
	else
		cout << t << endl;
}

int main() {
	int num = 3;
	int* pNum = &num;

	cout << getValue(num) << endl;
	cout << getValue(pNum) << endl;

	getValue2(num);
	getValue2(pNum);
}