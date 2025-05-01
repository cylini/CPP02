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

bool Fixed::operator>(const Fixed &other) const // overload of the > operator
{
	return this->_fixedPointValue > other._fixedPointValue; // on compare les valeurs des objets
}
bool Fixed::operator<(const Fixed &other) const // overload of the < operator
{
	return this->_fixedPointValue < other._fixedPointValue; // on compare les valeurs des objets
}
bool Fixed::operator>=(const Fixed &other) const // overload of the >= operator
{
	return this->_fixedPointValue >= other._fixedPointValue; // on compare les valeurs des objets
}
bool Fixed::operator<=(const Fixed &other) const // overload of the <= operator
{
	return this->_fixedPointValue <= other._fixedPointValue; // on compare les valeurs des objets
}
bool Fixed::operator==(const Fixed &other) const // overload of the == operator
{
	return this->_fixedPointValue == other._fixedPointValue; // on compare les valeurs des objets
}
bool Fixed::operator!=(const Fixed &other) const // overload of the != operator
{
	return this->_fixedPointValue != other._fixedPointValue; // on compare les valeurs des objets
}
Fixed Fixed::operator+(const Fixed &other) const // overload of the + operator
{
	return Fixed(this->toFloat() + other.toFloat()); // on additionne les valeurs des objets
}
Fixed Fixed::operator-(const Fixed &other) const // overload of the - operator
{
	return Fixed(this->toFloat() - other.toFloat()); // on soustrait les valeurs des objets
}
Fixed Fixed::operator*(const Fixed &other) const // overload of the * operator
{
	return Fixed(this->toFloat() * other.toFloat()); // on multiplie les valeurs des objets
}
Fixed Fixed::operator/(const Fixed &other) const // overload of the / operator
{
	return Fixed(this->toFloat() / other.toFloat()); // on divise les valeurs des objets
}
Fixed &Fixed::operator++() // prefix increment
{
	this->_fixedPointValue++; // on incremente la valeur de l'objet
	return *this;			  // retourne l'objet
}
Fixed Fixed::operator++(int) // postfix increment
{
	Fixed temp = *this;		  // on copie l'objet
	this->_fixedPointValue++; // on incremente la valeur de l'objet
	return temp;			  // retourne l'objet copie
}
Fixed &Fixed::operator--() // prefix decrement
{
	this->_fixedPointValue--; // on decremente la valeur de l'objet
	return *this;			  // retourne l'objet
}
Fixed Fixed::operator--(int) // postfix decrement
{
	Fixed temp = *this;		  // on copie l'objet
	this->_fixedPointValue--; // on decremente la valeur de l'objet
	return temp;			  // retourne l'objet copie
}
Fixed &Fixed::min(Fixed &a, Fixed &b) // min function for non-const references
{
	return (a < b) ? a : b; // retourne la valeur la plus petite
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) // min function for const references
{
	return (a < b) ? a : b; // retourne la valeur la plus petite
}
Fixed &Fixed::max(Fixed &a, Fixed &b) // max function for non-const references
{
	return (a > b) ? a : b; // retourne la valeur la plus grande
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) // max function for const references
{
	return (a > b) ? a : b; // retourne la valeur la plus grande
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // overload of the << operator
{
	out << fixed.toFloat(); // on affiche la valeur de l'objet
	return out;				// retourne l'objet
}
