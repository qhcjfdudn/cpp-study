#include <iostream>

using std::cout;
using std::endl;

template<typename T, int N>
class Stack {
	size_t _size;
	T _items[N];
public:
	Stack() : _size(0), _items{} {}
	~Stack() {}

	void push(T item);
	void pop();
	T top();
};

// 정의를 분리하고자 한다면 아래처럼 하면 된다.
template<typename T, int N>
void Stack<T, N>::push(T item) {
	if (_size < N) {
		_items[_size++] = item;
	}
	else throw std::out_of_range("overflow");
}

template<typename T, int N>
void Stack<T, N>::pop() {
	if (_size == 0) throw std::out_of_range("underflow");
	--_size;
}

template<typename T, int N>
T Stack<T, N>::top() {
	if (_size == 0) throw std::out_of_range("underflow");
	return _items[_size - 1];
}

int main() {
	Stack<int, 2> st1;
	st1.push(3);
	st1.push(2);
	cout << st1.top() << endl;
	st1.pop();
	cout << st1.top() << endl;
	st1.push(5);
	cout << st1.top() << endl;

	try {
		st1.push(1);	// error
	}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}
}