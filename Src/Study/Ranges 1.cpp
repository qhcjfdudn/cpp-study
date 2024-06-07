#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
	std::vector<int> v{ 1, 4, 2, 3 };
	std::ranges::sort(v.begin(), v.end());
	auto it = std::ranges::find(v, 3);

	std::cout << it - v.begin() << std::endl;

	for (auto it : v)
		std::cout << it << " ";
}