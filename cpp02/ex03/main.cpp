#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point outside(10, 10);
	Point edge(5, 0);

	std::cout << "Inside (3,3): " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside (10,10): " << bsp(a, b, c, outside) << std::endl;
	std::cout << "On edge (5,0): " << bsp(a, b, c, edge) << std::endl;

	return 0;
}
