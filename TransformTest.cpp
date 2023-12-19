#include <iostream>
#include <iomanip>
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"

using namespace std;

void TransformTest()
{

	cout << "---------- TRANSFORM TEST ----------" << endl;

	Transform T;
	T.setAngles(0, 0, -90.0);
	T.setTrans(100, 500, 50);
	Point p, pp, a, list_point;
	PointCloud pc, tst;

	p.setPoint(150, 150, -50);
	a.setPoint(2, 5, 1);
	double* ang, * tr;
	ang = T.getAngles();
	tr = T.getTrans();
	cout << "Angles:" << endl;;
	cout << "---------------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "angle " << i + 1 << ":"
			<< *(ang + i) << endl;
	}
	cout << "---------------------------" << endl;
	cout << "Trans:" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "value " << i + 1 << ":"
			<< *(tr + i) << endl;
	}
	cout << "---------------------------" << endl;

	T.setRotation(T.getAngles());
	cout << "Rotation Matrix" << endl;
	cout << "---------------------------" << endl;
	//T.display_rotation();
	cout << "---------------------------" << endl;
	cout << "Translation Matrix" << endl;
	cout << "---------------------------" << endl;
	T.setTranslation(T.getTrans());
	//T.display_translation();
	cout << "---------------------------" << endl;
	pp = T.doTransform(p);
	cout << "p After Transformation:" << endl
		<< "---------------------------" << endl
		<< endl << "X:" << pp.getX() << endl << "Y:" << pp.getY() << endl << "Z:" << pp.getZ() << endl;
	cout << "---------------------------" << endl;

	list<Point>test, lp;
	list<Point>::iterator it;
	pc.setPointCloud(p);
	pc.setPointCloud(a);
	tst = T.doTransform(pc);
	lp = tst.getPointCloud();
	int k = 1;
	cout << " Point Cloud After Transformation:" << endl;
	cout << "---------------------------" << endl;
	for (it = lp.begin(); it != lp.end(); ++it) {
		list_point = *it;
		cout << "Point " << k << endl;
		cout << "X:" << list_point.getX() << endl << "Y:"
			<< list_point.getY() << endl << "Z:" << list_point.getZ() << endl << endl;
		k++;
	}

}