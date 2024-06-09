#include <iostream>
#include <vector>

void print(std::vector<int> v) {
	for (auto val : v) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main() {
	// 아래 두 경우는 결과가 같을까요?
	std::vector<int> v1(3, 4);
	std::vector<int> v2{ 3, 4 };

	// 다릅니다ㅜ
	print(v1);	// 4 4 4
	print(v2);	// 3 4
}