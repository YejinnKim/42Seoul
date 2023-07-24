#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(int const value)
{
	this->value = value << bits;
}

Fixed::Fixed(float const value)
{
	this->value = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	value = fixed.getRawBits();
}

Fixed & Fixed::operator = (const Fixed& fixed)
{
	if (this != &fixed)
		value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

int		Fixed::getRawBits() const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat() const
{
	return ((float)value / (1 << bits));
}

int		Fixed::toInt() const
{
	return (value >> bits);
}

std::ostream & operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator > (Fixed const &ref) const
{
	return getRawBits() > ref.getRawBits();
}

bool	Fixed::operator < (Fixed const &ref) const
{
	return getRawBits() < ref.getRawBits();
}

bool	Fixed::operator >= (Fixed const &ref) const
{
	return getRawBits() >= ref.getRawBits();
}

bool	Fixed::operator <= (Fixed const &ref) const
{
	return getRawBits() <= ref.getRawBits();	
}

bool	Fixed::operator == (Fixed const &ref) const
{
	return getRawBits() == ref.getRawBits();
}

bool	Fixed::operator != (Fixed const &ref) const
{
	return getRawBits() != ref.getRawBits();
}

Fixed	Fixed::operator + (Fixed const &ref)
{
	return Fixed(toFloat() + ref.toFloat());
}

Fixed	Fixed::operator - (Fixed const &ref)
{
	return Fixed(toFloat() - ref.toFloat());
}

Fixed	Fixed::operator * (Fixed const &ref)
{
	return Fixed(toFloat() * ref.toFloat());
}

Fixed	Fixed::operator / (Fixed const &ref)
{
	return Fixed(toFloat() / ref.toFloat());
}

Fixed&	Fixed::operator ++ ()
{
	this->value++;
	return *this;
}

const Fixed	Fixed::operator ++ (int)
{
	const Fixed	tmp(*this);
	this->value++;
	return tmp;
}

Fixed&	Fixed::operator -- ()
{
	this->value--;
	return *this;
}

const Fixed	Fixed::operator -- (int)
{
	const Fixed	tmp(*this);
	this->value--;
	return tmp;
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}
