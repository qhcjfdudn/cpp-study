#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;

template<typename T>
void foo(T&& v) {	// 값, lvalue, rvalue reference 3가지를 다 받을 수 있다.
	cout.setf(std::ios_base::boolalpha);
	cout << "lvalue ref T: " << std::is_lvalue_reference_v<T> << endl;
	cout << "rvalue ref T: " << std::is_rvalue_reference_v<T> << endl;
	cout << "lvalue ref T&: " << std::is_lvalue_reference_v<T&> << endl;
	cout << "rvalue ref T&: " << std::is_rvalue_reference_v<T&> << endl;
	cout << "lvalue ref T&&: " << std::is_lvalue_reference_v<T&&> << endl;
	cout << "rvalue ref T&&: " << std::is_rvalue_reference_v<T&&> << endl;
	cout.unsetf(std::ios_base::boolalpha);

	// T는 그저 int인데, T&&의 최종 평가가 T&가 되었다. int 변수를 할당해도.
	// 따라서 아래가 성립. -> template/auto와 &&의 사용은, 컴파일하면 참조가 된다.
	v = 5;
}

template<typename T>
void goo(T& v) {
	cout << "lvalue ref T: " << std::is_lvalue_reference_v<T> << endl; // 0
	// 그런데 파라미터를 T&&로 쓰고 변수, 참조자를 전달하면 1
	
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)> << endl;
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)&> << endl;
	cout << "lvalue ref v: " << std::is_lvalue_reference_v<decltype(v)&&> << endl;
}

// 규칙
// 템플릿으로 받은 T, 코드에서 붙인 ref -> 평가 ref 결과
// && -> &&
// & & -> &
// & && -> &
// && & -> &
// && && -> &&
//

// 결국 컴파일할 경우 T&, T&& 각각으로 만들어질 것이다. T로는 만들어지지 않는다?
// 테스트해본 결과가 그렇게 의미한다. 모든 결과가 reference로 나온다.
// template의 type T는.. T 자체는 원래 레퍼런스를 받을 수 없다. decltype으로 보니
// 결과는 레퍼런스가 없다.
// 그런데 template/auto와 함께 쓰면 reference를 받도록 만들어진다.
// 그리고 만들어진 T을 찍어보면 reference로 출력 된다. 신기하다.
//

int main() {
	int num = 1;
	int& num1 = num;

	foo(num);
	cout << endl;
	foo(num1);
	cout << endl;
	foo(3);			// lvalue ref T / rvalue ref T 모두 false 출력. 알 듯 말 듯..
	cout << endl;

	goo(num1);
}