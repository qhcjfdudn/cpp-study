#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template<typename T>
class Stack {
	std::vector<T> _items;
public:
	Stack() : _items{} {}
	~Stack() {}

	void push(T item);
	void pop();
	T top();
};

template<typename T>
void Stack<T>::push(T item) {
	_items.push_back(item);
}

template<typename T>
void Stack<T>::pop() {
	if (_items.size() == 0) throw std::out_of_range("underflow");
	_items.pop_back();
}

template<typename T>
T Stack<T>::top() {
	if (_items.size() == 0) throw std::out_of_range("underflow");
	return *_items.rbegin();
}

int main() {
	Stack<int> st1;
	st1.push(3);
	st1.push(2);
	cout << st1.top() << endl;
	st1.pop();
	cout << st1.top() << endl;
	st1.push(5);
	cout << st1.top() << endl;

	try {
		st1.pop();
		st1.pop();
		st1.pop();
		st1.pop();
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}
}