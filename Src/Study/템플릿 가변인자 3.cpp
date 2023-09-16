#include <iostream>

template<typename T>
auto sum_nums(T value) { return value; }

template<typename T, typename... Nums>
auto sum_nums(T value, Nums... nums) {
	return value + sum_nums(nums...);
}

template<typename... Nums>
auto get_average(Nums... nums) {
	return static_cast<double>(sum_nums(nums...)) / sizeof...(nums);	// 개수를 알고 평균 구하기 가능. index 같은거 넘겨줄 필요 x
}

int main() {
	std::cout << get_average(5, 2.8, 1, 3.1f) << std::endl;
}