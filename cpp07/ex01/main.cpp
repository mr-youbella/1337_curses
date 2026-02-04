#include <iostream>
#include "iter.hpp"

template <typename T>
	void print(const T &x)
	{
		std::cout << x << '\n';
	}

void addOne(int &x)
{
	x++;
}

int main()
{
	int	a[] = {1, 2, 3, 4, 5};

	size_t lenA = sizeof(a) / sizeof(a[0]);
	std::cout << "Print int array:\n";
	iter(a, lenA, print<int>);
	std::cout << "After addOne:\n";
	iter(a, lenA, addOne);
	iter(a, lenA, print<int>);
	std::string s[] = {"hello", "world", "1337"};
	size_t lenS = sizeof(s) / sizeof(s[0]);
	std::cout << "Print string array:\n";
	iter(s, lenS, print<std::string>);
	const int ca[] = {10, 20, 30};
	size_t lenC = sizeof(ca) / sizeof(ca[0]);																						
	std::cout << "Print const int array:\n";
	iter(ca, lenC, print<int>);
	return (0);
}
