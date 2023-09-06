#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Test {
public:
	int* num;

	Test(int* num) : num(num) {}
	~Test() {
		cout << "~Test" << endl;
		delete num;
	}
};

void func() {
	throw "error: func";
}

int main() try {

	Test t(new int(4));
	cout << *t.num << endl;
	//	std::unique_ptr<Test> t1(new Test());
//	std::shared_ptr<Test> t2 = std::make_shared<Test>();
	func();
}	// t가 scope을 벗어나면서 t가 소멸되며 동적할당된 변수도 회수
catch (const char* e) {
	cout << e << endl;
}