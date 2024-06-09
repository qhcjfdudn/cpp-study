#include <iostream>
#include <string>
#include <algorithm>

class Test {
	int x_, y_;
	// 함수를 friend로 지정하기.
	friend std::ostream& operator<< (std::ostream&, const Test&);
public:
	Test(int x, int y) : x_(x), y_(y) {}

	auto operator<=>(const Test& rhs) const = default;
};

// 구현부
std::ostream& operator<< (std::ostream& os, const Test& rhs) {
	return os << rhs.x_ << " " << rhs.y_;
}

int main() {
	Test x[3] = { { 1, 2 }, { 2, 1 }, { 1, 1 } };
	std::sort(x, x + 3);
	std::cout << x[0] << " " << x[1] << " " << x[2] << std::endl;
	// 1 1 1 2 2 1
}