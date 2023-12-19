#include "PointCloudRecorder.h"
#include "DepthCamera.h"

void PointCloudRecorderTest()
{
	cout << "\n POINTCLOUD RECORDER TEST" << endl;
	cout << " -----------------------------------------------" << endl;
	PointCloud pc;
	PointCloudRecorder rec;
	DepthCamera dc;

	Point p1, p2, p3, p4;
	
	p1.setPoint(0, 0, 0);
	p2.setPoint(1, 2, 3);
	p3.setPoint(4, 5, 6);
	p4.setPoint(7, 8, 9);


	pc.setPointCloud(p1);
	pc.setPointCloud(p2);
	pc.setPointCloud(p3);
	pc.setPointCloud(p4);


	rec.setFileName("PointCloudRecorder_Test.txt");
	rec.save(pc);
	cout << " PointCloudRecorder Test edildi." << endl;
	cout << " Nokta bulutu PointCloudRecorder_Test.txt dosyasinin icine yazildi." << endl;
	cout << " -----------------------------------------------" << endl;

}
