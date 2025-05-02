#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}
Point::Point(const float x, const float y) : _x(x), _y(y) // constructor with parameters
{
	std::cout << "Constructor with parameters called" << std::endl;
}
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
}
Point &Point::operator=(const Point &copy) // copy assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) // si l'objet n'est pas le meme
	{
		this->_x = copy._x; // on copie la valeur de l'objet
		this->_y = copy._y; // on copie la valeur de l'objet
	}
	return *this; // retourne l'objet
}
Point::~Point() // destructor
{
	std::cout << "Destructor called" << std::endl;
}
const Fixed Point::getXFixed() const // getter for x
{
	return this->_x; // retourne la valeur de l'objet
}
const Fixed Point::getYFixed() const // getter for y
{
	return this->_y; // retourne la valeur de l'objet
}
