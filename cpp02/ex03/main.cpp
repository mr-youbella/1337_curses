#include "Point.hpp"

int main()
{
	Point a, b(10, 0), c(5, 5);
	Point p(5, 4);

	if (bsp(a, b, c, p))
		std::cout << "\033[32;1mInside\033[0m\n";
	else
		std::cout << "\033[31;1mOutside\033[0m\n";

	return 0;
}
