#include <iostream>
#include <cmath>

class Fixed{
private:
	int fxPtNum;
	static const int fracbits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed& other);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& val);
