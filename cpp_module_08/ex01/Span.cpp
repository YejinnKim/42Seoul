#include "Span.hpp"

Span::Span()
{
	n = 0;
}

Span::Span(unsigned int n)
{
	this->n = n;
}

Span::Span(const Span &obj)
{
	v = obj.v;
	n = obj.n;
}

Span& Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		v = obj.v;
		n = obj.n;
	}
	return *this;
}

Span::~Span() { }

void	Span::addNumber(int value)
{
	try
	{
		if (v.size() == n)
			throw std::logic_error("Vector is full!");
		v.push_back(value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Span::printNumber()
{
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int	Span::shortestSpan()
{
	try
	{
		if (v.size() < 2)
			throw std::logic_error("Vector size is less then 2!");
		std::vector<int> diff(v.size());
		std::adjacent_difference(v.begin(), v.end(), diff.begin());
		for (size_t i=0; i<diff.size(); i++)
			diff[i] = std::abs(diff[i]);
		int min = *std::min_element(++diff.begin(), diff.end());
		return min;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
}

int	Span::longestSpan()
{
	try
	{
		if (v.size() < 2)
			throw std::logic_error("Vector size is less then 2!");
		int max = *std::max_element(v.begin(), v.end());
		int min = *std::min_element(v.begin(), v.end());
		return max - min;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
}
