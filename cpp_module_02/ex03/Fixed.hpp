#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		const static int	bits = 8;
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &fixed);
		Fixed& operator = (const Fixed &fixed);
		~Fixed();
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat() const;
		int		toInt() const;

		bool	operator > (Fixed const &ref) const;
		bool	operator < (Fixed const &ref) const;
		bool	operator >= (Fixed const &ref) const;
		bool	operator <= (Fixed const &ref) const;
		bool	operator == (Fixed const &ref) const;
		bool	operator != (Fixed const &ref) const;

		Fixed	operator + (Fixed const &ref);
		Fixed	operator - (Fixed const &ref);
		Fixed	operator * (Fixed const &ref);
		Fixed	operator / (Fixed const &ref);

		Fixed&		operator ++ ();
		const Fixed	operator ++ (int);
		Fixed&		operator -- ();
		const Fixed	operator -- (int);

		static Fixed&		min(Fixed &ref1, Fixed &ref2);
		static const Fixed&	min(Fixed const &ref1, Fixed const &ref2);
		static Fixed&		max(Fixed &ref1, Fixed &ref2);
		static const Fixed&	max(Fixed const &ref1, Fixed const &ref2);
};

std::ostream& operator << (std::ostream &out, const Fixed &fixed);

#endif
