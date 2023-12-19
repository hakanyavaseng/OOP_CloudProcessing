#include<iostream>
#include"Point.h"
using namespace std;
void PointTest()
{
	cout << " POINT TEST" << endl;
	cout << " -----------------------------------------------" << endl;
	Point P1, P2, P3, P4;
	P1.setPoint(0, 0, 0);
	P2.setPoint(5, 12, 0);
	P3.setPoint(6, 8, 0);
	P4.setPoint(3, 4, 0);

	cout << " P1: (" << P1.getX() << "," << P1.getY() << "," << P1.getZ() << ")" << endl;
	cout << " P2: (" << P2.getX() << "," << P2.getY() << "," << P2.getZ() << ")" << endl;

	if (P1 == P2)
		cout << " P1 = P2" << endl;
	else
		cout << " P1 != P2" << endl;
	cout << " P1 ve p2 noktalari arasi uzaklik: " << P1.distance(P2) << endl;


	cout << " P3: (" << P3.getX() << "," << P3.getY() << "," << P3.getZ() << ")" << endl;
	cout << " P4: (" << P4.getX() << "," << P4.getY() << "," << P4.getZ() << ")" << endl;
	if (P3 == P4)
		cout << " P3 = P4" << endl;
	else
		cout << " P3 != P4" << endl;
	cout << " P3 ve P4 noktalari arasi uzaklik: " << P3.distance(P4) << endl;
	cout << " -----------------------------------------------" << endl;;
}
