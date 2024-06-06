#include <iostream>
#include <algorithm>
#include <list>
#include <concepts>

template<typename I> requires std::random_access_iterator<I>
void my_sort(I& begin, I& end) {
	std::sort(begin, end);
}

int main() {
	std::list<int> li;
	// std::sort(li.begin(), li.end());	// Editor���� ������ ������ ������
										// �������ϸ� ������ ������ ������
	my_sort(li.begin(), li.end());	// concept�� ���� ������ �ٷ� �����ָ� ���� ���뵵 �����ϴ�.
}