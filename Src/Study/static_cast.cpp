#include <iostream>
using namespace std;

class ClassA {};
class ClassB {};
class ClassC {
public:
	ClassC(int num) {
		cout << num << endl;
	}
};
class ClassD {
public:
	explicit ClassD(int num) {
		cout << num << endl;
	}
	explicit operator bool() const {
		return true;
	}
};

enum class TypeA {
	A, B, C
};
enum TypeB {
	A, B, C
};

class Parent {};
class Child : public Parent {};

int main() {
	ClassA a;
//	ClassB* b = (ClassB*)&a;				// C Style Casting
//	ClassB* b = static_cast<ClassB*>(&a);	// 컴파일 에러로 알려준다.

	float f = 1.1f;						
	int* i1 = (int*)&f;					// 되지만 위험
//	int* i2 = static_cast<int*>(&f);	// 컴파일 에러 알려줌.

	// 아래는 enum의 예시.
	TypeA t1 = static_cast<TypeA>(0);
	TypeB t2 = static_cast<TypeB>(t1);

	cout << static_cast<int>(t1) << endl;
	cout << static_cast<int>(t2) << endl;

	ClassC c1 = 1;
	ClassC c2 = ClassC(1);
	ClassC c3 = static_cast<ClassC>(1);

//	ClassD d1 = 1;						// error. explicit.
	ClassD d2 = static_cast<ClassD>(1);	// 됨.
//	bool b1 = d2;						// error. explicit
	bool b3 = bool(d2);					// 됨. 함수 스타일 캐스팅. 그치만 위험한 스타일.
	bool b2 = static_cast<bool>(d2);	// 됨.

	Parent p;
	Child& c = static_cast<Child&>(p);	// 다운 캐스팅 - 컴파일 됨.
										// 멤버 접근시 에러가 있을 수 있음.
										// static_cast 말고 다른 접근이 필요
}