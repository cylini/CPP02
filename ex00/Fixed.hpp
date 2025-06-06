#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
};
#endif