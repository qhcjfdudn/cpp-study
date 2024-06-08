#include <iostream>
#include <vector>

template<typename T>
void my_swap(T& a, T& b)
{
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

template<typename T, typename C>
void my_sort(C& v, T cmp) {
	int len = static_cast<int>(v.size());

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (cmp(v[i], v[j])) {
				my_swap(v[i], v[j]);
			}
		}
	}
}

int main() {
	std::vector<int> v{ 1, 4, 3, 2, 5 };

	my_sort(v, [](int a, int b)
		{
			return a > b;
		});

	for (auto val : v)
		std::cout << val << " ";
}