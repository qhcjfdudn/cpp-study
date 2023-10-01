#include <iostream>

template<typename T>
void foo(T t) {}

//auto bar() {
//	return { 1, 2 };	// 중괄호로 묶인 목록이 반환 형식을 제공하지 않음
//}

template<typename T>
auto bar(T t) {
	return { 1, 2 };	// error C2440: 'return': 'initializer list'에서 'auto'(으)로 변환할 수 없습니다.
}

int main() {
	int num(10);
	int num1{ 10 };

	auto num2(10);
	auto num3{ 10 };

	auto nums = { 1, 2 };	// std::initializer_list<int>

	// foo({ 1, 2 }); // 컴파일 에러.
	bar(1);	// error C2440
}