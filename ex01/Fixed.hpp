#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();							 // default constructor
	~Fixed();							 // destructor
	Fixed(const Fixed &copy);			 // copy constructor
	Fixed &operator=(const Fixed &copy); // copy assignment operator
	int getRawBits(void) const;			 // getter
	void setRawBits(int const raw);		 // setter

	Fixed(const int intValue);	   // constructor from int
	Fixed(const float floatValue); // constructor from float
	float toFloat(void) const;	   // conversion to float
	int toInt(void) const;		   // conversion to int
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // overload of the << operator

#endif