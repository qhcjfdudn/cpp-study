#include <iostream>

using std::cout;
using std::endl;

template<typename T, typename S>
void add(T t, S s) {
	T ret = t + s;
	cout << ret << endl;
}

template<typename T, typename S>
void add2(T t, S s) {
	auto ret = t + s;		// 여기가 핵심~
	cout << ret << endl;
}

template<typename T, typename S>
auto add3(T t, S s) {	// C++14부터 decltype 같은 trailing 없이 사용 가능
	return t + s;
}

template<typename T, typename S>
auto add4(T t, S s) -> decltype(t + s) {	// return 타입을 정의하는 문법.
	//	decltype(t + s) ret = t + s; // 이렇게도 사용 가능
	return t + s;
}

template<typename T, typename S>
auto add5(T t, S s) -> decltype(t + s) {	// 이 경우 decltype이 없으면 컴파일 에러. 반드시 필요.
	if (t < s) return t;
	return s;
}

//template<typename T, typename S>
//auto add6(T t, S s) {	// 컴파일 에러
//	if (t < s) return t;
//	return s;
//}

int main() {
	add(1, 1.2);	// 2
	add(1.2, 1);	// 2.2

	add2(1, 1.2);	// 2.2
	add2(1.2, 1);	// 2.2

	cout << add3(1, 1.2) << endl;

	// add6(1, 1.2); // 컴파일 에러 발생. decltype이 없어서.
}