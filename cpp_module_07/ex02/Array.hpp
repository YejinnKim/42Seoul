#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T 		*arr;
		size_t	len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		Array& operator=(const Array &obj);
		~Array();
		T& operator[](size_t i);
		size_t size() const;
};

#include "Array.tpp"

#endif
