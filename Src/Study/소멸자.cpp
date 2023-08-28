#include <iostream>
using namespace std;

class Player {
	int _num;
public:
	Player(int num) : _num(num) {
		cout << "Constructor : " << _num << endl;
	}
	~Player() {
		cout << "Destructor : " << _num << endl;
	}
//	~Player() = delete;	// 메모리에서 해제할 수 없다..
};

int main() {
	
	
}