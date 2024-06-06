#include <iostream>
#include <type_traits>
#include <concepts>

template<typename T>
concept has_num = requires {	// ���ڰ� ������ �Ұ�ȣ ���� ����
	T::num;
};

template<typename T>
concept has_type = requires {
	typename T::type;
};

template<typename T>
concept has_num_and_type = has_num<T> && has_type<T>;

template<typename T>
concept has_num_or_type = has_num<T> || has_type<T>;

template<typename T, typename S>
concept addable = requires(T a, S b) {
	a + b;
}
&& std::is_integral_v<T>
&& std::is_integral_v<S>;

template<typename T, typename S>
void add(T a, S b) requires addable<T, S>
{
	a + b;
}

struct Node {
	int num = 10;
};

struct Node2 {
	// int num = 10;
};

template<typename T>
void has_num_f() requires has_num<T>
{}

class Test {
public:
	int num;
};
int main() {
	add(1, 3);	// OK
	add(1, 1f);	// ERROR. 1f�� integer�� �ƴϴ�.

	has_num_f<Node>();	// OK
	has_num_f<Node2>();	// ERROR. Node2 ����ü�� num ����� ���� ���� �ʴ�.
}