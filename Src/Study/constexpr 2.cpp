#include <iostream>

using std::cout;
using std::endl;

struct Item {
	int _power;
	// constexpr 생성자
	constexpr Item(int power) : _power(power) {}

	constexpr Item operator+(const Item& other) const {
		return Item(_power + other._power);
	}
};

struct Item1 {
	int _power;
	// constexpr 생성자가 없더라도, 멤버가 모두 리터럴이기 때문에 암시적으로 동작한다.

	constexpr Item1 operator+(const Item1& other) const {
		return Item1{ _power + other._power };	// 그런데 중괄호 초기화로 만들어야만 동작하네??
		// return Item1(_power + other._power);	// error. 생성자가 없다고 한다.
	}
};

int main() {
	constexpr Item item0(4);
	constexpr Item item1(5);

	constexpr Item newItem = item0 + item1;

	int nums[newItem._power]; // 상수 시간에 _power가 결정됨을 의미.

	constexpr Item1 it0{ 3 };
	constexpr Item1 it1{ 1 };

	constexpr Item1 it2 = it0 + it1;
}