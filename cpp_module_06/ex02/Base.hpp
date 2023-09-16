#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
	private:
		std::string type;
	public:
		virtual	~Base();
		Base*	generate();
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
