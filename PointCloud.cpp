#include "PointCloud.h"

PointCloud::PointCloud()
{
	//! PointCloud sýnýfý için constructor
}


PointCloud::~PointCloud()
{
	//! PointCloud sýnýfý için destructor.
}
void PointCloud::setPointCloud(Point& p)
{
	//! bu fonksiyon pointcloud sýnýfýnýn içinde bulunun points nesnesine deðer atama iþlevi görür
	points.push_back(p);
}

void PointCloud::setPointCloud(list<Point> plist)
{
	points.clear();
	points = plist;
}

list<Point> PointCloud::getPointCloud() const
{
	//! bu fonksiyon pointcloud sýnýfýnýn içindeki points deðerlerini döndürür
	return points;
}

int PointCloud::getPointNumber() const
{
	//! bu fonksiyon PointCloud sýnýfý içindeki pointNumber deðiþkenini return eder
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
