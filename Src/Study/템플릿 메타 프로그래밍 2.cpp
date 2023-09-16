#include <iostream>

using std::cout;
using std::endl;

int fibo(int N) {
	if (N <= 1) return N;
	return fibo(N - 1) + fibo(N - 2);
}

template<int N>
struct Fibo {
	static const int value = Fibo<N - 1>::value + Fibo<N - 2>::value;
};

template<>
struct Fibo<0> {
	static const int value = 0;
};

template<>
struct Fibo<1> {
	static const int value = 1;
};

int main() {
	cout << Fibo<40>::value << endl;	// 아주 빠르게 동작
	cout << fibo(40) << endl;			// 느려..!
}