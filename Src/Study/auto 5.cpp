#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using std::cout;
using std::endl;

int main() {
	// pair
	std::map<int, std::string> m{ {1, "hello"} };

	// auto iter = m.begin(); �̰� ������~
	const auto& [key, value] = *m.begin();	// �̰� pair
	cout << key << endl;
	cout << value << endl;

	// array
	int nums[] = { 1, 2, 3, 4 };	// ���� �迭
	
	auto [a, b, c, d] = nums;
	cout << a << " " << b << " " << c << " " << d << endl; // 1 2 3 4

	int nums2[] = { 1, 2 };
	auto& [a1, b1] = nums2;
	a1 = 10;

	cout << a1 << " " << b1 << endl;	// 10 4

	// tuple
	std::tuple<int, float, std::string> t0{ 1, 2.0, "hi" };

	// auto ����
	int x0;
	float y0;
	std::string s0;
	std::tie(x0, y0, s0) = t0;
	
	// �ϳ��� �����´ٸ� �Ʒ��� ����
	cout << std::get<1>(t0) << endl; // 2

	cout << x0 << " " << y0 << " " << s0 << endl; // 1 2 hi

	// auto ����. ���Ǽ� ���־��� ����
	auto [x1, y1, s1] = t0;
	cout << x1 << " " << y1 << " " << s1 << endl; // 1 2 hi
}