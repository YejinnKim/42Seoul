#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj) { *this = obj; }

RPN& RPN::operator=(const RPN &obj)
{
	if (this != &obj)
		this->stack = obj.stack;
	return *this;
}

RPN::~RPN() {}

bool	RPN::isoperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	else
		return false;
}

int	RPN::calculator(char op)
{
	int num1 = stack.top();
	stack.pop();
	int num2 = stack.top();
	stack.pop();

	if (op == '+')
		return num2 + num1;
	else if (op == '-')
		return num2 - num1;
	else if (op == '/')
	{
		if (num1 == 0)
			printError();
		return num2 / num1;
	}
	else
		return num2 * num1;
}

void	RPN::calculate(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i]))
			stack.push(input[i] - '0');
		else if (isoperator(input[i]) && stack.size() >= 2)
			stack.push(calculator(input[i]));
		else
			printError();
	}
	if (stack.size() != 1)
		printError();
	else
		std::cout << stack.top() << std::endl;
}

void	printError()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
