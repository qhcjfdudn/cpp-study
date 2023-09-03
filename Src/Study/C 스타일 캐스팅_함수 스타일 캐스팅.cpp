#include <iostream>

using std::cout;
using std::endl;

using ParentPointer = Parent*;

class Parent {
public:
	Parent() {}
	explicit Parent(int i) {}
};

int main() {
	Parent p = Parent(10);	// 생성자 호출
	ParentPointer pp = ParentPointer(&p);	// 생성자 호출처럼 생겼지만
											// 형변환
}