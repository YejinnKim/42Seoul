#include "Point.hpp"

int main()
{
	Point	a(1, 1);
	Point	b(1, 5);
	Point	c(3, 1);
	Point	point(2, 2);
	bool	ret = bsp(a, b, c, point);

	if (ret)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}
