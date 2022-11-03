#include "Fixed.hpp"

Fixed::Fixed(void):fxPtNum(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float flt)
{
	fxPtNum = round(flt * (1 << fracbits));
}

Fixed::Fixed(long integer)
{
	fxPtNum = integer << fracbits;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other):fxPtNum(other.fxPtNum)
{
	std::cout << "Copy assignement operator called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (fxPtNum >> fracbits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fxPtNum)/static_cast<float>(1 << fracbits));
}

std::ostream& operator<<(std::ostream& stream, const Fixed& val)
{
	stream << val.toFloat();
	return (stream);
}

bool Fixed::operator>(const Fixed& other)
{
	return (fxPtNum > other.fxPtNum);
}

bool Fixed::operator<(const Fixed& other)
{
	return (fxPtNum < other.fxPtNum);
}

bool Fixed::operator>=(const Fixed& other)
{
	return (fxPtNum >= other.fxPtNum);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (fxPtNum <= other.fxPtNum);
}

bool Fixed::operator==(const Fixed& other)
{
	return (fxPtNum == other.fxPtNum);
}
bool Fixed::operator!=(const Fixed& other)
{
	return !(fxPtNum == other.fxPtNum);
}

Fixed Fixed::operator+(const Fixed &other)
{
	return Fixed(fxPtNum + other.fxPtNum);
}

Fixed Fixed::operator-(const Fixed &other)
{
	return Fixed(fxPtNum - other.fxPtNum);
}

Fixed Fixed::operator*(const Fixed &other)
{
	return Fixed(static_cast<float>(fxPtNum) * static_cast<float>(other.fxPtNum) / static_cast<float>(1 << 16));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return Fixed(fxPtNum / other.fxPtNum);
}

Fixed& Fixed::operator++()
{
	fxPtNum += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--()
{
	fxPtNum -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return temp;
}

Fixed& Fixed::max(Fixed& fxPtA, Fixed& fxPtB)
{
	if (fxPtA > fxPtB)
		return (fxPtA);
	return (fxPtB);
}

Fixed& Fixed::max(const Fixed& fxPtA, const Fixed& fxPtB)
{
	if (const_cast<Fixed &>(fxPtA) > const_cast<Fixed &>(fxPtB))
		return (const_cast<Fixed &>(fxPtA));
	return (const_cast<Fixed &>(fxPtB));
}

Fixed& Fixed::min(Fixed& fxPtA, Fixed& fxPtB)
{
	if (fxPtA < fxPtB)
		return fxPtA;
	return (fxPtB);
}

Fixed& Fixed::min(const Fixed& fxPtA, const Fixed& fxPtB)
{
	if (const_cast<Fixed &>(fxPtA) < const_cast<Fixed &>(fxPtB))
		return (const_cast<Fixed &>(fxPtA));
	return (const_cast<Fixed &>(fxPtB));
}
