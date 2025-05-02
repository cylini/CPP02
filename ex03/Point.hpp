#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point();
		
		// float getX() const;
		// float getY() const;
		// void setX(float x);
		// void setY(float y);
		const Fixed getXFixed() const;
		const Fixed getYFixed() const;
};



#endif