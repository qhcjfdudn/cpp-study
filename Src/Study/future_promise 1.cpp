#include <iostream>
#include <future>

int main() {
	std::promise<int> pi;
	std::future<int> fi = pi.get_future();

	pi.set_value(4);
	// pi.set_value(4);		// 2번 set하면 error
	std::cout << fi.get() << std::endl;
	// std::cout << fi.get() << std::endl;	// 2번 get하면 error

	// 반드시 set 1번, get 1번이어야 한다.
	//그리고 만약 set이 없이 get을 한다면, block된 채로 set을 기다린다.
}