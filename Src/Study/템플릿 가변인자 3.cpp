#include <iostream>

template<typename T>
auto sum_nums(T value) { return value; }

template<typename T, typename... Nums>
auto sum_nums(T value, Nums... nums) {
	return value + sum_nums(nums...);
}

template<typename... Nums>
auto get_average(Nums... nums) {
	return static_cast<double>(sum_nums(nums...)) / sizeof...(nums);	// ������ �˰� ��� ���ϱ� ����. index ������ �Ѱ��� �ʿ� x
}

int main() {
	std::cout << get_average(5, 2.8, 1, 3.1f) << std::endl;
}