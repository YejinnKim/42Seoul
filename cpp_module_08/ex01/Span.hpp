#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

class Span
{
	private:
		std::vector<int>	v;
		unsigned int		n;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		~Span();

		void	addNumber(int value);
		void	addManyNumbers();
		void	printNumber();
		int		shortestSpan();
		int		longestSpan();
};

#endif
