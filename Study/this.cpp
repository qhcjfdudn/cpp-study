#include <iostream>
using namespace std;

class Book {
	int page;
	bool isColor;
	
	Book(int page = 0, bool isColor = false)
		: page(page), isColor(isColor) {}

public:
	class Builder {
		int page;
		bool isColor;
	public:
		Book build() {
			return Book{ page, isColor };
		}
		Builder& setPage(int page) {
			this->page = page;
			return *this;
		}
		Builder& setColor(bool color) {
			this->isColor = color;
			return *this;
		}
	};

	void print() {
		cout << page << " " << isColor << endl;
	}
};

int main() {
	
	Book b = Book::Builder().setPage(10).setColor(false).build();
	b.print();
}