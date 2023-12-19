#pragma once
#include <iostream>
#include <Eigen/Dense>
#include "Point.h"
#include "PointCloud.h"


using namespace std;




class Transform {
private:
    // acilari tutan vector
    Eigen::Vector3d *angles;
    // orijinler arasýndaki uzaklýk farkýnýn kordinatlarýný veren vektör
    Eigen::Vector3d *trans;
    // transformation matrixi
    Eigen::Matrix4d *transMatrix;
    // rotasyon matrisi
    Eigen::Matrix3d *rotationMatrix;

public:
    // Transform sýnýfýnýn constructor fonksiyonu
    Transform() {
        angles = new Eigen::Vector3d;
        trans = new Eigen::Vector3d;
        transMatrix = new Eigen::Matrix4d;
        rotationMatrix = new Eigen::Matrix3d;
    }
    // Transform sýnýfýnýn destructor fonksiyonu
    ~Transform();
    // Bu fonnksiyon alinan aci degerlerini set eder.
    void setAngles(double, double, double);
    // Bu fonksiyon alýnan açý deðerlerini gördüðümüz fonksiyon.
    double* getAngles();
    // Bu fonksiyon iki kordinat düzleminin orijinleri arasýndaki uzaklýklarý trans arraye deðiþken olarak atar.
    void setTrans(double, double, double);
    // Burada iki kordinat düzlemi arasýnda uzaklýk deðerlerini veren x y z deðerlerini döndürür.
    double* getTrans();
    // Bu fonksiyon set edilen angle degerlerini kullanarak rotation matrix i doldurur
    void setRotation(double ang[3]);
    // Bu fonksiyon bize verilen rotasyon matrisini rotationmatrixe set eder .
    void setRotation(Eigen::Matrix3d ang);

    void setTranslation(double tr[3]);

    void setTranslation(Eigen::Vector3d tr);
    // bu fonksiyon 4x4 transform matrisini oluþturur bunun için rotasyonmatrix ve trans nesnesinin x y z sini kullanýr
   
    Point doTransform(Point p);
    // bu fonksiyon nokta bulutunu dönüþtürür, dönüþtürülmüþ nokta bulutunu döndürür
    PointCloud doTransform(PointCloud& pc);

    list<Point> doTransform(list<Point> lp);

};

