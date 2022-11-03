#include <iostream>

class Fixed{
private:
	int fxptnum;
	static const int fracbits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	int getRawBits( void ) const;
	void setRawBits( int const raw);
};
