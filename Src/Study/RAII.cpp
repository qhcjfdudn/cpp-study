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
}	// t�� scope�� ����鼭 t�� �Ҹ�Ǹ� �����Ҵ�� ������ ȸ��
catch (const char* e) {
	cout << e << endl;
}