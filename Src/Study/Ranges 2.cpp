#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

int main() {
	// view

	std::vector<int> v(10);
	std::iota(v.begin(), v.end(), 0);

	for (auto it : v)			// 10개 짜리 벡터를 출력
		std::cout << it << " ";	// 0 1 2 3 4 5 6 7 8 9
	std::cout << std::endl;

	// ranges::views::iota. for문의 1바퀴 돌 때마다 숫자를 하나씩
	// 만들어준다. 함수가 맨처음 호출될 때 전체를 다 만드는 게 아니라
	// 호출될 때마다 하나씩 만들어 준다. lazy하다.
	for (auto it : std::ranges::views::iota(0, 10))
		std::cout << it << " ";	// 0 1 2 3 4 5 6 7 8 9

	// 아래 구문을 실행하면 무한대로 계속 숫자를 증가시키며 출력한다.
	// for (auto it : std::ranges::views::iota(0))
	//	std::cout << it << " ";	// 0 1 2 3 ...
	
}