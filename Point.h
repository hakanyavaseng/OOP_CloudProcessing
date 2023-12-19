#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Point
{
private:
	double x, y, z;

public:
	// Point s�n�f�n�n constructoru.
	Point();
	// Point s�n�f� i�in destructor
	~Point();
	// bir pointe kordinatlar�n� atar.
	Point setPoint(double x, double y, double z);
	// noktanın kordinatlarını kullanmamızı sağlar.
	void getPoint(double& _x, double& _y, double& _z) const
	{
			_x = x;
			_y = y;
			_z = z;
	}
	// iki nokta aras�ndaki uzakl��� verir.
	double distance(const Point&);
	// noktan�n x de�erini d�nd�r�r.
	double getX() const;
	// noktan�n y de�erini d�nd�r�r.
	double getY() const;
	// noktan�n z de�erini d�nd�r�r.
	double getZ() const;
	// iki noktan�n e�it olup olmad���n� denetler.
	bool operator==(const Point&) const;
};
