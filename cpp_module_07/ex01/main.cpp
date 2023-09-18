#include "iter.hpp"

int main()
{
	int intArr[5] = {1, 2, 3, 4, 5};
	char charArr[5] = {'a', 'b', 'c', 'd', 'e'};

	::iter<int>(intArr, 5, printValue);
	std::cout << std::endl;
	::iter<char>(charArr, 5, printValue);
	
	return 0;
}
