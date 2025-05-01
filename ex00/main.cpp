#include "Fixed.hpp"

int main(void)
{
	Fixed a;	// Default constructor
	Fixed b(a); // Copy constructor
	Fixed c;	// Default constructor
	c = b;		// Copy assignment operator
	// Fixed d;		 // Default constructor
	// d.setRawBits(5); // Setter

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	// std::cout << d.getRawBits() << std::endl;
	return 0;
}