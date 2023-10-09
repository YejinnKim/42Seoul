#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN &obj);
		RPN& operator=(const RPN &obj);
		~RPN();

		void	calculate(const std::string &input);
		int		calculator(char op);
		bool	isoperator(char c);
};

void	printError();

#endif
