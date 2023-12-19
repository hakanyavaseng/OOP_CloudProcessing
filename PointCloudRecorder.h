#pragma once
#include "PointCloud.h"

using namespace std;

class PointCloudRecorder 
{
private:
    string fileName;

public:
    // bu fonksiyon PointCloudRecorder sýnýfýnýn constructoru
    PointCloudRecorder();
    // bu fonksiyon PointCloudRecorder sýnýfýnýn destructoru
    ~PointCloudRecorder();
    // bu fonksiyon
    void setFileName(string);
    // bu fonksiyon
    string getFileName();
    // bu fonksiyon nokta bulutlarýný dosyaya kaydeder
    bool save(const PointCloud& pc);
};

