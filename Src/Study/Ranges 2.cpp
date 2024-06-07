#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

int main() {
	// view

	std::vector<int> v(10);
	std::iota(v.begin(), v.end(), 0);

	for (auto it : v)			// 10�� ¥�� ���͸� ���
		std::cout << it << " ";	// 0 1 2 3 4 5 6 7 8 9
	std::cout << std::endl;

	// ranges::views::iota. for���� 1���� �� ������ ���ڸ� �ϳ���
	// ������ش�. �Լ��� ��ó�� ȣ��� �� ��ü�� �� ����� �� �ƴ϶�
	// ȣ��� ������ �ϳ��� ����� �ش�. lazy�ϴ�.
	for (auto it : std::ranges::views::iota(0, 10))
		std::cout << it << " ";	// 0 1 2 3 4 5 6 7 8 9

	// �Ʒ� ������ �����ϸ� ���Ѵ�� ��� ���ڸ� ������Ű�� ����Ѵ�.
	// for (auto it : std::ranges::views::iota(0))
	//	std::cout << it << " ";	// 0 1 2 3 ...
	
}