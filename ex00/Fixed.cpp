#include "Fixed.hpp"

Fixed::Fixed(void):fxptnum(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	setRawBits(other.fxptnum);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fxptnum >> fracbits);
}

void Fixed::setRawBits( int const raw)
{
	fxptnum = raw << fracbits;
}
