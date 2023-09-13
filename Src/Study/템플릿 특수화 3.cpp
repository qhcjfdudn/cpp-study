#include <iostream>	
#include <vector>

using std::cout;
using std::endl;

template<typename T>
class Stack {
	std::vector<T> items;
public:
	void push(T item) {
		items.push_back(item);
	}
};

template<>
void Stack<int>::push(int item) {
	cout << "Stack::int" << endl;
}

int main() {
	Stack<int> st1;
	st1.push(1);	// "Stack::int"
	Stack<float> st2;
	st2.push(1.1f);
}