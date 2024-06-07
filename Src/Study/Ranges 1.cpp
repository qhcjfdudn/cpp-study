#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
	// Algorithm

	std::vector<int> v{ 1, 4, 2, 3 };
	std::ranges::sort(v.begin(), v.end());
	auto it = std::ranges::find(v, 3);

	std::cout << it - v.begin() << std::endl;	// 2

	for (auto it : v)
		std::cout << it << " ";	// 1 2 3 4
	std::cout << std::endl;

	auto it2 = v.begin();
	std::ranges::advance(it2, 2);
	std::cout << *it2 << std::endl;	// 3
}