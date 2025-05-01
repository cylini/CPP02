#include "Fixed.hpp"

int main(void)
{
	// Fixed a;	// default constructor
	// Fixed b(a); // copy constructor
	// Fixed c;	// default constructor
	// c = b;		// copy assignment operator

	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;
	// std::cout << "c: " << c << std::endl;

	// Fixed d(42.42f); // constructor from float
	// std::cout << "d: " << d << std::endl;

	// Fixed e(42); // constructor from int
	// std::cout << "e: " << e << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}