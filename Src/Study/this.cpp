#include <iostream>
using namespace std;

class Book {
	int page;
	bool isColor;
	
	Book(int page = 0, bool isColor = false)
		: page(page), isColor(isColor) {}

public:
	class Builder {
		int page;		// 생성할 객체와
		bool isColor;	// 똑같이 멤버를 사용
	public:
		Builder(int page) : page(page), isColor(false) {}

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
	Book b = Book::Builder(20).setPage(10).setColor(false).build();
	b.print();
}