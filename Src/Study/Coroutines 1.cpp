#include <iostream>
#include <experimental/generator>

std::experimental::generator<int> gen() {
	std::cout << "gen0" << std::endl;
	co_yield 0;
	std::cout << "gen1" << std::endl;
	co_yield 1;
	std::cout << "gen2" << std::endl;
	co_yield 2;
	std::cout << "gen3" << std::endl;
	co_yield 3;
}

int main() {
	auto g = gen();
	std::cout << "main" << std::endl;				// main

	auto iter = g.begin();							// gen0

	std::cout << "main0" << std::endl;				// main0
	std::cout << *iter << std::endl;				// 0
	++iter;	// 이 부분에서 coroutine을 재개한다.	// gen1

	std::cout << "main1" << std::endl;				// main1
	std::cout << *iter << std::endl;				// 1
	++iter;											// gen2
	std::cout << "main2" << std::endl;				// main2
	std::cout << *iter << std::endl;				// 2
	++iter;											// gen3
	std::cout << "main3" << std::endl;				// main3
	std::cout << *iter << std::endl;				// 3
}