#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	return find(container.begin(), container.end(), value);
}

#endif
