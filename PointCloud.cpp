#include "PointCloud.h"

PointCloud::PointCloud()
{
	//! PointCloud s�n�f� i�in constructor
}


PointCloud::~PointCloud()
{
	//! PointCloud s�n�f� i�in destructor.
}
void PointCloud::setPointCloud(Point& p)
{
	//! bu fonksiyon pointcloud s�n�f�n�n i�inde bulunun points nesnesine de�er atama i�levi g�r�r
	points.push_back(p);
}

void PointCloud::setPointCloud(list<Point> plist)
{
	points.clear();
	points = plist;
}

list<Point> PointCloud::getPointCloud() const
{
	//! bu fonksiyon pointcloud s�n�f�n�n i�indeki points de�erlerini d�nd�r�r
	return points;
}

int PointCloud::getPointNumber() const
{
	//! bu fonksiyon PointCloud s�n�f� i�indeki pointNumber de�i�kenini return eder
	return points.size();
}

PointCloud PointCloud::operator+(const PointCloud& firstobject)
{
	PointCloud sumPC;
	sumPC = *this;

	std::list<Point> temp = firstobject.getPointCloud();
	for (int i = 0; i < firstobject.getPointNumber(); i++)
	{
		sumPC.setPointCloud(temp.front());
		temp.pop_front();
	}

	return sumPC;
}

const PointCloud& PointCloud::operator=(const PointCloud& firstObject)
{
	list<Point> temp = firstObject.getPointCloud();

	if (&firstObject != this)
	{
		points.clear();
		for (int i = 0; i < firstObject.getPointNumber(); i++)
		{
			this->setPointCloud(temp.front());
			temp.pop_front();
		}
	}

	return *this;
}
