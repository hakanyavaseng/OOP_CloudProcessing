#pragma once
#include "Transform.h"
using namespace std;


class Transform;

class PointCloudGenerator
{
private:
	Transform transform;

public:
	PointCloudGenerator(){}
	Transform getTransform()
	{
		return this->transform;
	}
	virtual PointCloud capture()=0;
	virtual PointCloud captureFor()=0;
};

