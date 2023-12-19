#pragma once
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "PointCloudGenerator.h"
#include "Map.h"

class PointCloud;
class PointCloudRecorder;
class PointCloudGenerator;
class Map;

#include <vector>
class MapperInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;

public:
	//! constructor
	MapperInterface() {}
	//! constructor 
	MapperInterface(PointCloud pointCloud, PointCloud patch, PointCloudGenerator* pcg, PointCloudRecorder* pcr, Map* map)
	{
		this->pointCloud = pointCloud;
		this->patch = patch;
		this->recorder = pcr;
		this->addGenerator(pcg);
		this->map = map;
	}
	//! PointCloudGenerator nesnesi ekler
	void addGenerator(PointCloudGenerator* generator);
	//! PointCloudRecorder nesnesi ayarlar
	virtual void setRecorder(PointCloudRecorder* rcd);
	//! nokta bulutunu oluşturur
	virtual	bool generate();
	//! Nokta bulutunu kaydeder
	virtual	bool recordPointCloud();
	//! haritaya kaydeder
	virtual bool recordMap();
	//! haritayı yükler
	virtual	bool insertMap();


};


