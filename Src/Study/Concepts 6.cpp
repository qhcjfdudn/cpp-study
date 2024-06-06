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
	// std::sort(li.begin(), li.end());	// Editor에서 에러로 보이지 않지만
										// 컴파일하면 에러가 ㅎㄷㄷ 무서움
	my_sort(li.begin(), li.end());	// concept를 쓰면 에러를 바로 보여주며 에러 내용도 간단하다.
}