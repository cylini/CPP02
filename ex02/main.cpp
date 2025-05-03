#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));		// multiplication
	std::cout << "1:" << a << std::endl;		// 0
	std::cout << "2:" << ++a << std::endl;		// 0 + 1 = 1 , affiche 1 direct
	std::cout << "3:" << a << std::endl;		// 1
	std::cout << "4:" << a++ << std::endl;		// 1 + 1 = 2, mais affiche 1 d'abord
	std::cout << "5:" << a << std::endl;		// ici affiche 2
	std::cout << "6:" << b << std::endl;		// 5.05 * 2 = 10.1
	std::cout << Fixed::max(a, b) << std::endl; // 10,1 car 10.1 > 2
	return 0;
}