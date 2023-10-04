#include <iostream>

using std::cout;
using std::endl;

struct Item {
	int _power;
	// constexpr ������
	constexpr Item(int power) : _power(power) {}

	constexpr Item operator+(const Item& other) const {
		return Item(_power + other._power);
	}
};

struct Item1 {
	int _power;
	// constexpr �����ڰ� ������, ����� ��� ���ͷ��̱� ������ �Ͻ������� �����Ѵ�.

	constexpr Item1 operator+(const Item1& other) const {
		return Item1{ _power + other._power };	// �׷��� �߰�ȣ �ʱ�ȭ�� �����߸� �����ϳ�??
		// return Item1(_power + other._power);	// error. �����ڰ� ���ٰ� �Ѵ�.
	}
};

int main() {
	constexpr Item item0(4);
	constexpr Item item1(5);

	constexpr Item newItem = item0 + item1;

	int nums[newItem._power]; // ��� �ð��� _power�� �������� �ǹ�.

	constexpr Item1 it0{ 3 };
	constexpr Item1 it1{ 1 };

	constexpr Item1 it2 = it0 + it1;
}