#include "Fixed.hpp"

Fixed::Fixed(void):fxPtNum(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float flt)
{
	fxPtNum = round(flt * (1 << fracbits));
}

Fixed::Fixed(int integer)
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
