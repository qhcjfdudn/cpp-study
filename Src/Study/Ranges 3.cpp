#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std::ranges;

int main() {
	// views - '|' 파이프 합성
	// 숫자가 커지더라도 lazy하기 때문에 효율적으로 동작한다.

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