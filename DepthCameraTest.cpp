#include "DepthCamera.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"

void DepthCameraTest()

{
	cout << "\n DEPT_CAMERA_TEST" << endl;
	cout << " -----------------------------------------------" << endl;
	DepthCamera dc;
	PointCloud pc;
	PointCloudRecorder rec;

	dc.setFileName("DepthCameraTest.txt");
	cout << " ";
	pc = dc.capture();
	rec.setFileName(dc.getFileName());
	rec.save(pc);
	cout << " -----------------------------------------------" << endl;
}
