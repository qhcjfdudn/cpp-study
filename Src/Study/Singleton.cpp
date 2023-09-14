#include <iostream>

using std::cout;
using std::endl;

class Singleton {
	Singleton() : _v(0) {}
	Singleton(const Singleton& s) : Singleton() {}
	Singleton& operator=(const Singleton& s) {}
	~Singleton() {}
public:
	int _v;
	static Singleton& getInstance() {
		static Singleton s;
		return s;
	}
};

int main() {
	Singleton& s1 = Singleton::getInstance();
	s1._v = 10;
	
	Singleton& s2 = Singleton::getInstance();
	s2._v = 20;

	// s1 = s2; 대입 연산자 재정의 통해서 대입도 막아주자.

	cout << s1._v << " " << s2._v << endl;
}