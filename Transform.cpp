#include "Transform.h"
#include <iterator>
#include <list>
#include<iostream>
#include<iomanip>
#include <math.h>
using namespace std;



Transform::~Transform() // destructor fonksiyonu
{
}

void Transform::setAngles(double gama, double beta, double alpha)
{
	using namespace Eigen;
	(*angles)(0) = gama;
	(*angles)(1) = beta;
	(*angles)(2) = alpha;
}

double* Transform::getAngles()
{
	// Bu fonksiyon al�nan a�� de�erlerini g�rd���m�z fonksiyon.
	double* ptr_angles = new double[3];
	for (int i = 0; i < 3; ++i)
	{
		ptr_angles[i] = (*angles)(i);
	}
	return ptr_angles;
}

void Transform::setTrans(double transitionx, double transitiony, double transitionz)
{
	// Bu fonksiyon iki koordinat merkezinin orjinleri arasindaki uzakliklari
	// degisken olarak alip, trans array'inin icine atar.
	using namespace Eigen;
	(* trans)(0) = transitionx;
	(*trans)(1) = transitiony;
	(*trans)(2) = transitionz;
}

double* Transform::getTrans()
{
	// Burada iki kordinat d�zlemi aras�nda uzakl�k de�erlerini veren x y z de�erlerini al�r�z.
	// Trans dizisindeki x y z de�erlerini g�rd���m�z fonksiyondur.
	double* ptr_trans = new double[3];
	for (int i = 0; i < 3; i++)
	{
		ptr_trans[i] = (*trans)(i);
	}
	return ptr_trans;
}

void Transform::setRotation(Eigen::Matrix3d ang)
{
	// ang[0] = gama  , ang[1] = beta , ang[2] = alpha
	// Bu fonksiyon set edilen angle degerlerini kullanarak
	// rotationMatrix'i doldurur.

	(*rotationMatrix)(0, 0) = ang(0, 0);
	(*rotationMatrix)(0, 1) = ang(0, 1);
	(*rotationMatrix)(0, 2) = ang(0, 2);
	(*rotationMatrix)(1, 0) = ang(1, 0);
	(*rotationMatrix)(1, 1) = ang(1, 1);
	(*rotationMatrix)(1, 2) = ang(1, 2);
	(*rotationMatrix)(2, 0) = ang(2, 0);
	(*rotationMatrix)(2, 1) = ang(2, 1);
	(*rotationMatrix)(2, 2) = ang(2, 2);
}

void Transform::setRotation(double ang[3])
{
	// Bu fonksiyon bize verilen rotasyon matrisini rotationmatrixe set eder .
	(*rotationMatrix)(0, 0) = cos(ang[2]) * cos(ang[1]);
	(*rotationMatrix)(0, 1) = (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0]));
	(*rotationMatrix)(0, 2) = (cos(ang[2]) * sin(ang[1]) * cos(ang[0])) + (sin(ang[2]) * sin(ang[0]));
	(*rotationMatrix)(1, 0) = sin(ang[2]) * cos(ang[1]);
	(*rotationMatrix)(1, 1) = (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0]));
	(*rotationMatrix)(1, 2) = (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0]));
	(*rotationMatrix)(2, 0) = -sin(ang[1]);
	(*rotationMatrix)(2, 1) = cos(ang[1]) * sin(ang[0]);
	(*rotationMatrix)(2, 2) = cos(ang[1]) * cos(ang[0]);
}

void Transform::setTranslation(Eigen::Vector3d tr)
{
	// bu fonksiyon transform nesnemizin i�indeki x y z de�erlerini alarak translation matrisi olu�turur
	// translation matrisinin 3x3 l�k k�sm� ratasyon matrisidir burda ilk �nce translation matrisine rotasyon matrisini ekliyoruz.


	for(int i=0; i<3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			(* this->transMatrix)(i, j) = (*rotationMatrix)(i, j);
		}
	}
	(*this->transMatrix)(3, 0) = 0;
	(*this->transMatrix)(3, 1) = 0;
	(*this->transMatrix)(3, 2) = 0;
	(*this->transMatrix)(3, 3) = 1;

	for (int k = 0; k < 3; k++)
	{
		(*transMatrix)(k, 3) = tr(k);
	}
}

void Transform::setTranslation(double tra[3])

{
	(*this->transMatrix)(3, 0) = 0;
	(*this->transMatrix)(3, 1) = 0;
	(*this->transMatrix)(3, 2) = 0;
	(*this->transMatrix)(3, 3) = 1;

	//Burda 3 e 3 luk rotasyon matrix ini transMatrix e yerlestircez.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			(*transMatrix)(i, j) = (* rotationMatrix)(i, j);
		}
	}

	//Son olarak da trans matrixini son sutuna yerlestiriyoruz.
	for (int k = 0; k < 3; k++)
	{
		(*transMatrix)(k, 3) = tra[k];
	}
	
}


PointCloud Transform::doTransform(PointCloud& pc)
{
	PointCloud new_pointCloud;
	list<Point>pTemp;
	pTemp = pc.getPointCloud();
	new_pointCloud.setPointCloud(doTransform(pTemp));
	return new_pointCloud;
}

list<Point> Transform::doTransform(list<Point> lp)
{
	list<Point> new_list;
	list<Point>::iterator iter;
	//list teki her bir pointe transform islemi uygulanir
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		new_list.push_back(doTransform(*iter));
	}
	return new_list;
}

Point Transform::doTransform(Point p)
{
	Point new_point;

	double p_cord[3];

	p_cord[0] = p.getX();
	p_cord[1] = p.getY();
	p_cord[2] = p.getZ();
	using namespace Eigen;
	Vector4d point1, point2;
	point2(0) = p_cord[0];
	point2(1) = p_cord[1];
	point2(2) = p_cord[2];
	point2(3) = 1;

	//Donusum matrisiyle point in noktalarinin carpim islemi
	point1 = (* transMatrix) * point2;

	//Donusturlmus noktanin koord set edilir.
	new_point.setPoint(point1(0), point1(1), point1(2));

	return new_point;
}

//
//void Transform::displayTranslation() const
//{
//	int i, j;
//	for (i = 0; i < 4; i++) {
//		for (j = 0; j < 4; j++) {
//			cout << setw(10) << right << this->transMatrix[i][j];
//		}
//		cout << endl;
//	}
//}
//
//void Transform::displayRotation() const
//{
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << setw(10) << right << this->rotationmatrix[i][j];
//		}
//		cout << endl;
//	}
//}
