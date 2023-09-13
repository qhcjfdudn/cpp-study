#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T, typename S>
class Test {
public:
	T a;
	S b;
};

template<>
class Test<int, int> {
public:
	int c;
};

template<typename T>
class Test<float, T> {
public:
	T d;
};

// 아래도 가능하나, 위의 경우와 함께 적용되어 모호한 상황이 생긴다.
template<typename T>
class Test<T, T> {
public:
	T e;
};

int main() {
	Test<int, float> t1;
	t1.a; t1.b;
	Test<int, int> t2;
	t2.c;
	//Test<float, float> t3;	// 모호한 경우.
	//t3.d;
	Test<float, int> t4;
	t4.d;
	Test<double, double> t5;
	t5.e;

	std::vector<int> vi;
	std::vector<bool> vb;
}