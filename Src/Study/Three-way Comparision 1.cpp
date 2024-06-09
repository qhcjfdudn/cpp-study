#include <iostream>
#include <string>
#include <algorithm>

class Test {
	int x_, y_;
	friend std::ostream& operator<< (std::ostream&, const Test&);

public:
	Test(int x, int y) : x_(x), y_(y) {}

	// 가장 간단한 형태.
	// 인자가 2개 이상이어도 비교가 된다.
	auto operator<=>(const Test& rhs) const = default;
};

std::ostream& operator<< (std::ostream& os, const Test& rhs) {
	return os << rhs.x_ << " " << rhs.y_;
}

int main() {
	Test a = { 1, 2 };
	Test b = { 2, 2 };
	Test c = { 2, 2 };

	std::cout << std::is_lt(a <=> b) << std::endl;	// 1
	std::cout << std::is_eq(a <=> b) << std::endl;	// 0
	std::cout << std::is_gt(a <=> b) << std::endl;	// 0

	std::cout << std::is_lt(b <=> c) << std::endl;	// 0
	std::cout << std::is_eq(b <=> c) << std::endl;	// 1
	std::cout << std::is_gt(b <=> c) << std::endl;	// 0

	Test x[3] = { { 1, 2 }, { 2, 1 }, { 1, 1 } };
	std::sort(x, x + 3);
	std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
	// 1 1 1 2 2 1
}