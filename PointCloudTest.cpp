#include <iostream>
#include "PointCloud.h"

using namespace std;

void PointCloudTest()
{
	cout << "\nPointCloud Test" << endl;
	cout << "---------------" << endl;

	Point p1, p2, p3, p4, p5, p6, p7;
	p2.setPoint(1, 2, 3);
	p3.setPoint(4, 5, 6);
	p4.setPoint(7, 8, 9);
	p5.setPoint(10, 11, 12);
	p6.setPoint(13, 14, 15);
	p7.setPoint(16, 17, 18);

	PointCloud pc1, pc2;

	pc1.setPointCloud(p1);
	pc1.setPointCloud(p2);
	pc1.setPointCloud(p3);
	pc2.setPointCloud(p4);
	pc2.setPointCloud(p5);
	pc2.setPointCloud(p6);
	pc2.setPointCloud(p7);

	std::list<Point> tempPoints;
	std::list<Point>::iterator iter;

	cout << "pc1 = {";

	tempPoints = pc1.getPointCloud();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == pc1.getPointCloud().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	cout << "pc2 = {";

	tempPoints = pc2.getPointCloud();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == pc2.getPointCloud().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	PointCloud pc3;
	pc3 = pc1 + pc2;
	cout << "pc3 = pc1 + pc2 = {";

	tempPoints = pc3.getPointCloud();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == pc3.getPointCloud().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc1 = pc2;
	cout << "pc1 = pc2" << endl;
	cout << "pc1 = {";

	tempPoints = pc1.getPointCloud();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == pc1.getPointCloud().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	std::list<Point> testPoints;
	Point p8, p9, p10;
	p8.setPoint(22, 33, 44);
	p9.setPoint(55, 66, 77);
	p10.setPoint(88, 99, 111);
	testPoints.push_back(p8);
	testPoints.push_back(p9);
	testPoints.push_back(p10);

	cout << "testPoints listesi = {";

	for (iter = testPoints.begin(); iter != testPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == testPoints.back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc2.setPointCloud(testPoints);
	cout << "pc2'nin points listesi testPoints listesi ile set edildi." << endl;
	cout << "pc2 = {";

	tempPoints = pc2.getPointCloud();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.getPoint(x, y, z);

		if (*iter == pc2.getPointCloud().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}
}