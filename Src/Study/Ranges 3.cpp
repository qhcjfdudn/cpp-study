#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std::ranges;

int main() {
	// views - '|' ������ �ռ�
	// ���ڰ� Ŀ������ lazy�ϱ� ������ ȿ�������� �����Ѵ�.

	auto r = views::iota(0, 30)
		| views::reverse
		| views::filter([](const int num)
			{
				return num % 2;
			})
		| views::take(7)
		| views::transform([](const int num)
			{
				return num * 2;
			});

	for (auto num : r)
		std::cout << num << " ";	// 58 54 50 46 42 38 34
}