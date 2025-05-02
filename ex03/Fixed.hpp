#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

#include <cmath>

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
	// comparison operators
	bool operator>(const Fixed &other) const;  // overload of the > operator
	bool operator<(const Fixed &other) const;  // overload of the < operator
	bool operator>=(const Fixed &other) const; // overload of the >= operator
	bool operator<=(const Fixed &other) const; // overload of the <= operator
	bool operator==(const Fixed &other) const; // overload of the == operator
	bool operator!=(const Fixed &other) const; // overload of the != operator
	// arithmetic operators
	Fixed operator+(const Fixed &other) const; // overload of the + operator
	Fixed operator-(const Fixed &other) const; // overload of the - operator
	Fixed operator*(const Fixed &other) const; // overload of the * operator
	Fixed operator/(const Fixed &other) const; // overload of the / operator
	// increment and decrement operators
	Fixed &operator++();   // prefix increment
	Fixed operator++(int); // postfix increment
	Fixed &operator--();   // prefix decrement
	Fixed operator--(int); // postfix decrement
	// min and max functions
	static Fixed &min(Fixed &a, Fixed &b);					 // min function for non-const references
	static const Fixed &min(const Fixed &a, const Fixed &b); // min function for const references
	static Fixed &max(Fixed &a, Fixed &b);					 // max function for non-const references
	static const Fixed &max(const Fixed &a, const Fixed &b); // max function for const references
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // overload of the << operator

#endif