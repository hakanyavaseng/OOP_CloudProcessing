#include <iostream>
#include "MapperInterface.h"
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloudGenerator.h"
#include "ThreeDGridMap.h"

//! Point sinifini test eder.
void PointTest();
//! PointCloud sinifinin uye fonksiyonlarini test eder.
void PointCloudTest();
//! PointCloudRecorder sinifini test eder.
void PointCloudRecorderTest();
//! 3DGridMap sinifini test eder.
void GridMapTest();
//! DepthCamera sinifini test eder.
void DepthCameraTest();
void TransformTest();


int main()
{
#if 0

	PointTest();
	PointCloudTest();
	PointCloudRecorderTest();
	DepthCameraTest();
	TransformTest();
	GridMapTest();
	return 0;

#elif 1

	DepthCamera dc1, dc2, dc3, dc4;
	PointCloud pc1, pc2, pc3, pc4;
	PointCloudRecorder rec1, rec2, rec3, rec4;
	Transform tr1, tr2, tr3, tr4;
	ThreeDGridMap tgm1(10), tgm2(10), tgm3(10), tgm4(10);


	dc1.setFileName("cam.txt");
	dc2.setFileName("cam1.txt");
	dc3.setFileName("cam2.txt");
	dc4.setFileName("cam3.txt");

	rec1.setFileName("cam.txt");
	rec2.setFileName("cam1.txt");
	rec3.setFileName("cam2.txt");
	rec4.setFileName("cam3.txt");

	pc1 = dc1.capture();
	pc2 = dc2.capture();
	pc3 = dc3.capture();
	pc4 = dc4.capture();


	cout << endl;
	//cam.txt
	Eigen::Matrix3d matrix1;
	matrix1(0,0)= -0.7076050;
	matrix1(0,1) = 0.0065031;
	matrix1(0,2) = -0.7065783;
	matrix1(1,0) = 0.7066082;
	matrix1(1,1) = 0.0065134;
	matrix1(1,2) = -0.7075750;
	matrix1(2,0) = 0.0000008;
	matrix1(2,1) = -0.9999576;
	matrix1(2,2) = -0.0092041;


	tr1.setTrans(1.95704, 1.93000, 1.05707);
	tr1.setRotation(matrix1);
	tr1.setTranslation(tr1.getTrans());
	pc1 = tr1.doTransform(pc1);
	rec1.save(pc1);



	cout << endl;
	//cam1.txt
	Eigen::Matrix3d matrix2;
	matrix2(0,0) = -0.6638364;
	matrix2(0,1) = -0.0068830;
	matrix2(0,2) = 0.7478462;
	matrix2(1,0) = -0.7478778;
	matrix2(1,1) = 0.0061099;
	matrix2(1,2) = -0.6638082;
	matrix2(2,0) = -0.0000002;
	matrix2(2,1) = -0.9999576;
	matrix2(2,2) = -0.0092036;
	tr2.setTrans(-1.91288, 1.94412, 1.05465);
	tr2.setRotation(matrix2);
	tr2.setTranslation(tr2.getTrans());
	pc2 = tr2.doTransform(pc2);
	rec2.save(pc2);



	cout << endl;
	//cam2.txt
	Eigen::Matrix3d matrix3;
	matrix3(0,0) = 0.8762180;
	matrix3(0,1) = 0.0044351;
	matrix3(0,2) = -0.4818945;
	matrix3(1,0) = 0.4819149;
	matrix3(1,1) = -0.0080638;
	matrix3(1,2) = 0.8761809;
	matrix3(2,0) = 0.0000001;
	matrix3(2,1) = -0.9999577;
	matrix3(2,2) = -0.0092030;
	tr3.setTrans(1.96978, -1.94622, 1.05264);
	tr3.setRotation(matrix3);
	tr3.setTranslation(tr3.getTrans());
	pc3 = tr3.doTransform(pc3);
	rec3.save(pc3);




	cout << endl;
	//cam3.txt
	Eigen::Matrix3d matrix4;
	matrix4(0,0)= 0.3597052;
	matrix4(0,1)= -0.0085871;
	matrix4(0,2)= 0.9330265;
	matrix4(1,0)= -0.9330660;
	matrix4(1,1)= -0.0033108;
	matrix4(1,2)= 0.3596900;
	matrix4(2,0)= 0.0000003;
	matrix4(2,1)= -0.9999576;
	matrix4(2,2)= -0.0092033;
	tr4.setTrans(-1.87445, -1.95027, 1.06432);
	tr4.setRotation(matrix4);
	tr4.setTranslation(tr4.getTrans());
	pc4 = tr4.doTransform(pc4);
	rec4.save(pc4);





	//3D Grid Map islemleri
	tgm1.setThreeDGridMap(1, 10);
	tgm1.loadMap(dc1.getFileName());
	tgm1.saveMap(rec1.getFileName());


	tgm2.setThreeDGridMap(1, 10);
	tgm2.loadMap(dc2.getFileName());
	tgm2.saveMap(rec2.getFileName());


	tgm3.setThreeDGridMap(1, 10);
	tgm3.loadMap(dc3.getFileName());
	tgm3.saveMap(rec3.getFileName());


	tgm4.setThreeDGridMap(1, 10);
	tgm4.loadMap(dc4.getFileName());
	tgm4.saveMap(rec4.getFileName());

	return 0;
#endif
}


