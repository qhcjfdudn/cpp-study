#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;

int func(int) {
	cout << "func" << endl;
	return 0;
}

int main() {
	auto i1 = 1u;
	unsigned int i2 = 1;
	
	std::vector<int> v;
	std::vector<int>::iterator iter = v.begin();

	auto iter2 = v.begin();

	auto iter3 = new int(10);

	std::map<int, int> m;
	// for (std::pair<int, int>& pair : m) {	// error
	for (std::pair<const int, int>& pair : m) {	// °¡´É
		
	}

	const int a = 10;
	const int& b = a;
	const int* c = &a;

	auto aa = a;	// int
	auto bb = b;	// int
	auto cc = c;	// const int*

	auto& bbb = b;	// auto = const int
	auto* ccc = c;	// auto = const int

	int nums[] = { 1, 2, 3 };
	auto nn = nums;		// int*
	auto& nnn = nums;	// int (&)[3]

	auto f = func;		// int (*f)(int)
	auto& f2 = func;	// int (&f2)(int)

	f(123);
	f2(123);
}