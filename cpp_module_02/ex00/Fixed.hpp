#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		const static int	bits;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed & operator = (const Fixed& obj);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
