#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Stack {
	size_t _size;
	size_t _capacity;
	T* _items;
public:
	Stack() : _size(0), _capacity(4), _items(new T[_capacity]) {}
	~Stack() {
		delete[] _items;
	}
	void push(T item) {
		if (_size < _capacity) {
			_items[_size++] = item;
		}
		else {
			size_t newCapacity = _capacity * 2;

			T* oldItems = _items;
			T* newItems = new T[newCapacity];

			std::copy(oldItems, oldItems + _capacity, newItems);

			_capacity = newCapacity;
			_items = newItems;

			delete[] oldItems;

			push(item);
		}
	}

	void pop() {
		--_size;
	}

	T& top() {
		return _items[_size - 1];
	}
};

int main() {
	Stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(5);

	cout << st1.top() << endl;
	st1.pop();
	cout << st1.top() << endl;

	Stack<std::string> st2;
	st2.push("abcd");

	cout << st2.top() << endl;

}