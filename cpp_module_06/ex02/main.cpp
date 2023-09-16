#include "Base.hpp"

int main()
{
	Base base;

	Base *test = base.generate();
	base.identify(*test);
	base.identify(test);
	
	delete test;

	return 0;
}
