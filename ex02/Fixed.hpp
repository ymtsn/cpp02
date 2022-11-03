#include <iostream>
#include <cmath>

class Fixed{
private:
	long fxPtNum;
	static const int fracbits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(long num);
	Fixed(float num);
	Fixed(const Fixed& other);
	float toFloat( void ) const;
	int toInt( void ) const;
	bool operator>(const Fixed& val);
	bool operator<(const Fixed& val);
	bool operator>=(const Fixed& val);
	bool operator<=(const Fixed& val);
	bool operator==(const Fixed& val);
	bool operator!=(const Fixed& val);
	Fixed operator+(const Fixed& val);
	Fixed operator-(const Fixed& val);
	Fixed operator*(const Fixed& val);
	Fixed operator/(const Fixed& val);
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed& max(Fixed& FxA, Fixed& FxB);
	static Fixed& max(const Fixed& FxA, const Fixed& FxB);
	static Fixed& min(Fixed& FxA, Fixed& FxB);
	static Fixed& min(const Fixed& FxA, const Fixed& FxB);
};

 std::ostream& operator<<(std::ostream& stream, const Fixed& val);

