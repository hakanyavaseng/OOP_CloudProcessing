#include "Point.h"
#include <math.h>
Point::Point()
{
	/**
	 *  Point s�n�f�n�n constructoru.
	 */
	this->setPoint(0, 0, 0);
}

Point::~Point()
{
	/**
	 *  Point s�n�f�n�n deconstructoru.
	 */
}

Point Point::setPoint(double x, double y, double z)
{
	/**
	 *  	noktanın x degerlerini dondurur.
	 */

	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

double Point::distance(const Point &p)
{
	/**
	 *  	iki nokta aras�ndaki uzakl��� d�nd�r�r.
	 */

	double d;
	d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
	return d;
}

double Point::getX() const
{
	/**
	 *  	noktan�n x de�erini d�nd�r�r.
	 */
	return x;
}

double Point::getY() const
{
	/**
	 *  	noktan�n y de�erini d�nd�r�r.
	 */
	return y;
}

double Point::getZ() const
{
	/**
	 *  	noktan�n z de�erini d�nd�r�r.
	 */
	return z;
}

bool Point::operator==(const Point &p) const
{
	/**
	 *  	iki noktan�n e�it olup olmad���n� denetler.
	 */
	if (x == p.x && y == p.y && z == p.z)
		return true;
	else
		return false;
}
