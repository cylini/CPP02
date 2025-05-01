#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() // destructor
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) // construit un nouvel objet en copiant un le contenu d'un autre
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed &Fixed::operator=(const Fixed &copy) // assigne a un objet deja existant le contenu d'un autre
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) // si l'objet n'est pas le meme
	{
		this->_fixedPointValue = copy.getRawBits(); // on copie la valeur de l'objet
	}
	return *this; // retourne l'objet
}
int Fixed::getRawBits(void) const // getter
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue; // retourne la valeur de l'objet
}
void Fixed::setRawBits(int const raw) // setter
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw; // on assigne la valeur de l'objet
}

Fixed::Fixed(const int value) // constructor from int
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits; // on decale la valeur de 8 bits a gauche
}
Fixed::Fixed(const float value) // constructor from float
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits)); // on multiplie la valeur par 2^8 et on arrondit
}

float Fixed::toFloat(void) const // conversion to float
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits); // on divise la valeur par 2^8
}
int Fixed::toInt(void) const // conversion to int
{
	return this->_fixedPointValue >> _fractionalBits; // on decale la valeur de 8 bits a droite
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // overload of the << operator
{
	out << fixed.toFloat(); // on affiche la valeur de l'objet
	return out;				// retourne l'objet
}
