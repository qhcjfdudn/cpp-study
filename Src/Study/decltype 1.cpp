#include <iostream>

using std::cout;
using std::endl;

int func(float) { return 10; }

int global_num = 10;
int& ref_func() {
	cout << "decltype()의 동작으로 함수 자체는 실행되지 않습니다." << endl;
	return global_num;
}

class Person {
public:
	float _height;
	float _weight;
};

int main() {
	decltype(1) num = 10;

	decltype(num) num1 = 20;		// int
	decltype(num1)& num2 = num1;	// int&
	decltype(num2) num3 = num1;		// int& . 레퍼런스를 추론할 수 있다.

	const decltype(num) num4 = num2;	// const int
	const decltype(num)& num5 = num2;	// const int&

	// 이름에 괄호 2개는 레퍼런스가 된다.
	// decltype((num)) num4 = 10;	// error. rvalue는 참조될 수 없어서.
	decltype((num)) num6 = num1;	// int&

	decltype(1 + 2.2f) num7 = 1.3f;	// float

	// 배열
	int nums[] = { 1, 2, 3 };

	// decltype은 배열을 포인터가 아닌 정적 배열 타입으로 받는다!!
	// decltype(nums) nums1 = { 1, 2, 3, 4, 5};	// 이니셜 라이저 값이 너무 많습니다.
	decltype(nums) nums2 = { 1, 2 }; // int nums2[3]
	decltype(nums) nums3{ 1, 2, 3 }; // int nums2[3]


	// 함수에 대한 사용
	auto f = func;
	cout << f(1.1f) << endl;
	decltype(func) f1;	// 함수 선언. 정의는 없다. 그래서 실행 링킹 에러 발생.
	// cout << f1(1.1f) << endl;	// fatal error LNK1120: 1개의 확인할 수 없는 외부 참조입니다.

	decltype(func)& f2 = func;
	decltype(func)* f3 = func;

	cout << f2(1.1f) << endl;
	cout << f3(1.1f) << endl;

	decltype(func(1.1f)) num8 = 40;
	
	decltype(ref_func()) num9 = num8;

	Person p;
	decltype(p._weight) weight0; // float

	// 값이 없어도 된다. 어차피 실행되지 않는다.
	// float으로 선언된 것만 컴파일 타임에 확인하기 때문.
	// 그래서 아래와 같이 사용 가능
	decltype(Person::_weight) weight1; // float
}